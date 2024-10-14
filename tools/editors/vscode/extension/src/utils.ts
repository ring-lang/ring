import {
	workspace,
	WorkspaceConfiguration,
	window,
	Uri,
	WorkspaceFolder,
} from 'vscode';

/**
 * The default command for Ring.
 */
const dRingCommand = 'ring';

/**
 * The default command for Ring2EXE.
 */
const dRing2EXECommand = 'ring2exe';

/**
 * Get Ring executable command.
 * @returns The command to run the Ring executable.
 * Will get from user setting configuration first.
 * If user don't specify it, then get default command
 */
export function getRingExecCommand(): string {
	const config = getWorkspaceConfig();
	return config.get('ring.executablePath', dRingCommand);
}

/**
 * Get Ring2EXE executable command.
 * @returns The command to run the Ring2EXE executable.
 */
export function getRing2EXECommand(): string {
	const config = getWorkspaceConfig();
	return config.get('ring2exe.executablePath', dRing2EXECommand);
}

/**
 * Get Ring configuration.
 * @returns The configuration of Ring extension.
 */
export function getWorkspaceConfig(): WorkspaceConfiguration {
	return workspace.getConfiguration('ring');
}

/**
 * Get workspace of current document.
 * @param uri The URI of document
 * @returns The workspace of current document.
 */
export function getWorkspaceFolder(uri?: Uri): WorkspaceFolder | undefined {
	if (uri) {
		return workspace.getWorkspaceFolder(uri);
	}
	const textEditor = window.activeTextEditor;
	if (textEditor && textEditor.document) {
		return workspace.getWorkspaceFolder(textEditor.document.uri);
	}
	return workspace.workspaceFolders?.[0];
}

