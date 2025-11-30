import {fetch} from 'undici';
import config from './config.js';

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

const pissedOffOne = `
    You're a pissed off dude. You're not here to help.
    You like to share crazy stories and you throw 'fucks' around.
    You speak and understand only English language - never use any other one while responding.
`;
const funnyOne = `
    You are a hilarious, witty, and slightly sarcastic AI named Chuckles.
    You love cracking jokes, making puns, and turning any conversation into a comedy show.
    Your humor is clever but never mean-spirited. You speak with playful energy, often exaggerating things for comic effect.
    Always keep the mood light and fun, and don't hesitate to poke fun at yourself or the situation.
`;
const personality = pissedOffOne.trim().replaceAll('\n    ', ' ');
const systemPrompt = { role: 'system', content: personality };
const chatHistory = [systemPrompt];
export default async (req, res) => {
    const promptMessage = req.body.prompt;
    const stream = req.body.stream;
    console.log(promptMessage);
    if (!promptMessage || typeof promptMessage !== 'string')
        return res.status(400).send('invalid prompt');
    chatHistory.push({ role: 'user', content: promptMessage });
    try {
        console.log(chatHistory);
        const ollamaRes = await fetch(config.ollama.url + '/api/chat', {
            method: 'POST',
            headers: {'Content-Type': 'application/json'},
            body: JSON.stringify({ model: config.ollama.model, messages: chatHistory, stream }),
        });
        if (!ollamaRes.ok || !ollamaRes.body) {
            console.error('ollama response error:', ollamaRes.status);
            return res.status(500).send(`ollama server error: ${ollamaRes.status}`);
        }
        res.setHeader('Content-Type', 'text/plain; charset=utf-8');
        res.setHeader('Transfer-Encoding', 'chunked');
        const reader = ollamaRes.body.getReader();
        const decoder = new TextDecoder('utf-8');
        let reply = "";
        while (true) {
            const {done, value} = await reader.read();
            if (done)
                break;
            const chunk = decoder.decode(value);
            res.write(chunk);
            console.log(chunk);
            try { reply += JSON.parse(chunk)?.message?.content || ''; }
            catch (ex) { console.log(ex, chunk); }
        }
        res.end();
        chatHistory.push({ role: 'assistant', content: reply });
    } catch (err) {
        console.error('fetch error:', err);
        res.status(500).send('internal server error');
    }
}