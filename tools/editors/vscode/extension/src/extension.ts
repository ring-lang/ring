import vscode, { ExtensionContext } from 'vscode';
import * as commands from './commands';

const cmds = {
	'ring.run': commands.run,
	'ring.clock': commands.clock,
	'ring.ring2exe': commands.ring2exe,
	'ring.ring2exe_static': commands.ring2exe_static,
	'ring.ring2exe_dist': commands.ring2exe_dist,
	'ring.ring2exe_dist_allruntime': commands.ring2exe_dist_allruntime
};

/**
 * This method is called when the extension is activated.
 * @param context The extension context
 */
export function activate(context: ExtensionContext): void {
	for (const cmd in cmds) {
		const handler = cmds[cmd] as () => void;
		const disposable = vscode.commands.registerCommand(cmd, handler);
		context.subscriptions.push(disposable);
	}

}