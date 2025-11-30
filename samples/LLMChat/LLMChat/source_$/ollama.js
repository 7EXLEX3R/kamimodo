import {spawn} from 'child_process';
import net from 'net';
import config from './config.js';

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

export default async () => {
    if (config.ollama.localRun) {
        function isOllamaRunning(port = config.ollama.url.split('://')[1].split(':')[1]) {
            return new Promise((resolve) => {
                const socket = net.createConnection(port, config.ollama.url.split('://')[1].split(':')[0]);
                socket.on('connect', () => { socket.end(); resolve(true); });
                socket.on('error', () => resolve(false));
            });
        }
        if (!(await isOllamaRunning())) {
            console.log('starting ollama...');
            spawn('ollama', ['serve'], {stdio: 'inherit'});
        } else console.log('ollama already running');
        const delay = (ms) => new Promise((res) => setTimeout(res, ms));
        await delay(2000);
    }
}