The Ring Package Manager (RingPM)
=================================

The RingPM will be distributed with the Ring language starting from Ring 1.10 

Usage
=====

	ringpm [command]
	Command : search  [keywords...]
	Command : refresh : Update the Registry (Packages List)
	Command : install <packagename> [from <UserName>] [branch <branchname>]
	Command : list    [-u : Check updates]
	Command : run     <packagename>
	Command : update  <packagename>
	Command : remove  <packagename>
	Command : format  : Delete All Packages
	Command : new     <packagename>
	Command : package : Create package in the current folder

Example
=======

To install the Ring Notepad package

	ringpm install ringnotepad

To run Ring Notepad

	ringpm run ringnotepad

Implementation
==============

The next lessons explains how to create the Ring Package Manager step by step.

<table>
	<tr>	
		<th>Index</th>
		<th>Content</th>
		<th>Links</th>
	</tr>
	<tr>
		<td id="lesson1">1</td>
		<td>
			Simple Start, We will start the project, Try to implement the Install, Remove and List commands (Initial Implementation).
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156167595515345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=EDyrgo-0BIg&index=1&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson2">2</td>
		<td>
			Update the program to support working as executable file, Separate the project to many source code files and write some tests.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156170147090345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=RWlo8Eiyo0s&index=2&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson3">3</td>
		<td>
			We will know the difference between SystemSilent() and System() functions, Then we will work faster using Batch Files, Then We will improve the style of the tests output using spaces and colors.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156170776415345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=EGoVTIbw8M0&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=3">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson4">4</td>
		<td>
			We will see the RingConsoleColors Document, Organize the project to more folders, Add the RingVersion attribute to the Package File, Then we will check the Ring Version when we install new packages.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156172518305345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=uBToCd6bYeE&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=4">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson5">5</td>
		<td>
			We will create special source code files for the Version and Folder functions, Also we will support installing packages that contains folders and sub folders.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156172625970345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=l3QebGntG4g&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=5">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson6">6</td>
		<td>
			We will support installing packages from local folder.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156178964340345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=Re4lxETIdm8&index=6&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson7">7</td>
		<td>
			We will improve the List command to display the package version and check for new updates.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156179872360345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=r_JX5Lw3U54&index=7&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson8">8</td>
		<td>
			Adding the Update command to update packages to newer versions
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156179966170345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=IQ1Q_9nvVCE&index=8&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson9">9</td>
		<td>
			Update the Remove command, Don't delete package if it's used by other packages, and when deleting a package, delete the related packages.
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156181825700345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=qPtMe4f9y9w&index=9&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson10">10</td>
		<td>
			If we have an error during installation of a package, display a message (Not Completed), Create Lock File for each package and don't repeat the same package in the lock file 
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156185979310345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=hpinzzgkBKk&index=10&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson11">11</td>
		<td>
			Better style for (Install, Remove, Update, etc) commands, Fast List ( list [-f : don't check updates] )	
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156186589925345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=3bSwT28aP1w&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=11">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson12">12</td>
		<td>
			Correct management for the state, The InstallCommand class, Better tests
		</td>
		<td>
			<a href="https://www.facebook.com/mahmoudfayed1986/videos/vb.640625344/10156188149035345/?type=2&video_source=user_video_tab">Facebook</a> <br />
			<a href="https://www.youtube.com/watch?v=B7pfTYsiPqg&index=12&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson13">13</td>
		<td>
			Installing more than one version from the same package
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=_WLo-d0WdCs&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=13">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson14">14</td>
		<td>
			Print Packages Count
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=YW7EXpa11h4&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=14">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson15">15</td>
		<td>
			Better format for Package and Lock files.
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=UDMkECTl3RU&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=15">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson16">16</td>
		<td>
			Format Command (Delete All Packages)
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=fFsbyFLS0sU&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=16">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson17">17</td>
		<td>
			Run Command 
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=aRnsWOi_euE&index=17&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson18">18</td>
		<td>
			Semantic Versioning and installing more than one major version of the same package 
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=c_LLHjWnUg4&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=18">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson19">19</td>
		<td>
			Select different branch based on the required package version, Easy loading for packages using the load command.
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=w8r7BP96rgQ&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=19">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson20">20</td>
		<td>
			Adding ringpm.exe to ring/bin, The New Command and Installing packages using GitHub User Name.
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=urxUIb35EDI&index=20&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson21">21</td>
		<td>
			The Search Command
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=nPSyNdLJZ2U&index=21&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson22">22</td>
		<td>
			The Refresh Command - Update the Registry (Packages List)
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=MjHRQgGFxbk&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=22">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson23">23</td>
		<td>
			The Package Command - Create a new package in the current folder
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=sT5r4O4I6FY&index=23&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn">YouTube</a>
		</td>
	</tr>
	<tr>
		<td id="lesson24">24</td>
		<td>
			Testing the Ring Package Manager on Linux
		</td>
		<td>
			<a href="https://www.youtube.com/watch?v=yTjwi55u0iA&list=PLpQiqjcu7CuFiv-Fa8M8wx-MrKvLmMnbn&index=24">YouTube</a>
		</td>
	</tr>
</table>

