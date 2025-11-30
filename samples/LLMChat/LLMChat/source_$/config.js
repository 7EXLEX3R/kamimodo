import fs from 'fs';
const aiJson = JSON.parse(fs.readFileSync('./config/ai.json', 'utf8'));

// kamimodo™ - the legacy of GODMODE_999 © 2025 ____l____e____x____e____r____

function expandConfig(config) {
    const resolved = { ...config };
    while (true) {
        let changedThisPass = false;
        for (const [key, value] of Object.entries(resolved)) {
            if (typeof value === 'string') {
                const newValue = value.replace(/\$\{(\w+)\}/g, (_, varName) =>
                    resolved[varName] !== undefined ? resolved[varName] : `\${${varName}}`);
                if (newValue !== value) {
                    resolved[key] = newValue;
                    changedThisPass = true;
                }
            }
        }
        if (!changedThisPass) break;
    }
    return resolved;
}
export default {...expandConfig(aiJson)};