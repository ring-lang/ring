# RingPM GUI - Ring Package Manager GUI

A graphical user interface for the Ring Package Manager (RingPM) built with Ring and RingQt.

## Features

- **Package Installation**: Install Ring packages by entering the package name
- **Package Management**: View all installed packages in a table format
- **Package Operations**: Run, update, and remove installed packages
- **Real-time Output**: View command output and progress in real-time
- **User-friendly Interface**: Clean and intuitive GUI design
  

<img width="896" height="720" alt="Capture" src="https://github.com/user-attachments/assets/6e666347-54ce-47b8-b9d0-8db28ac4f18a" />



## Interface Components

### Package Installation
- **Package Name Textbox**: Enter the name of the package to install
- **User Name Textbox**: Enter developer Github user name 
- **Install Button**: Click to install the specified package

### Installed Packages Table
Displays installed packages with the following columns:
- **Package Name**: The name of the installed package
- **Package Description**: Brief description of the package
- **Package Version**: Current version of the installed package

### Action Buttons
- **Run**: Execute the selected package
- **Update**: Update the selected package to the latest version
- **Remove**: Uninstall the selected package (with confirmation)
- **Close**: Exit the application

### Output Section
- **Output Textbox**: Displays real-time output from RingPM commands

## How It Works

1. **Package Installation**: The GUI calls RingPM using QProcess to install packages
2. **Package Listing**: Reads package information from the `tools/ringpm/packages` directory
3. **Command Execution**: All RingPM operations (install, run, update, remove) are executed via QProcess
4. **Real-time Feedback**: Command output is displayed in the output textbox as it happens

## Files Structure

- `ringpmguiController.ring` - Main application controller with business logic
- `ringpmguiView.ring` - GUI layout and visual components
- `README.md` - This documentation file

## Requirements

- Ring Programming Language
- RingQt (for GUI components)
- RingPM (Ring Package Manager)

## install
   ```
   ringpm install ringpmgui from azzeddine2017
   ```

## Usage

1. Run the application:
   ```
   ringpm run ringpmgui
   ```

2. **To install a package**:
   - Enter the package name in the textbox

3. **To manage installed packages**:
   - Select a package from the table
   - Use Run, Update, or Remove buttons as needed

4. **Monitor progress**:
   - Watch the output section for real-time feedback
   - Package table automatically refreshes after operations

## Integration with Ring Notepad

This tool is designed to be integrated into Ring Notepad as an external application, similar to the "Find in Files" feature. Ring developers using Ring Notepad will be able to manage packages without using the command line.

## Development

The application follows Ring GUI development patterns:
- MVC architecture with separate Controller and View files
- Event-driven programming using RingQt
- QProcess integration for external command execution
- Table widgets for data display
- Real-time output handling

## Contributing

This project is open for community contributions. Feel free to:
- Report bugs and issues
- Suggest new features
- Submit pull requests
- Improve documentation

## License

This project follows the same license as the Ring Programming Language.
