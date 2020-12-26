# RingLibui Extension

## Introduction

This extension provides complete support for the Libui library

Libui URL: https://github.com/andlabs/libui

Using this extension we can develop and distribute lightweight GUI Applications 
using Ring (Less than 1 MB)

Runtime files and their size

* Ring.dll (448 KB)
* Libui.dll (210 KB)
* Ring_Libui.dll (633 KB)
* Total : 1,291 KB without compressing the files 
* After compressing the files (To ZIP file) - Total : 504 KB

## Install

We can install this extension using the Ring Package Manager

	ringpm install ringlibui from ringpackages

## Samples

We have the samples in the ring/samples/UsingLibUI folder

URL: https://github.com/ring-lang/ring/tree/master/samples/UsingLibUI

## Example

``` ring
load "libui.ring"

oWindow = uiNewWindow( "Hello, World", 400, 400, True)
uiWindowOnClosing(oWindow,"closeApp()")

uiControlShow( oWindow )
uiMain()

func closeApp
	uiQuit()
```					

## Screen Shots

### Hello World

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_1.png)

### Message Box

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_2.png)

### Using Buttons

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_3.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_4.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_5.png)

### Controls

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_6.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_7.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_8.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_9.png)

### Say Something

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_10.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_11.png)

### Menubar

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_12.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_13.png)

### Histogram

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_14.png)

### Drawing Text

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_15.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_16.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_17.png)

### Drawing Shapes

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_18.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_19.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_20.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_21.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_22.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_23.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_24.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_25.png)

![RingLibuiScreenShot](https://github.com/ring-lang/ring/blob/master/documents/source/libui_26.png)