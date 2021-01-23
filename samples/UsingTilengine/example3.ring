#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

/* engine init */
TLN_Init(640,480,0,0,1)

/* load resources */
TLN_SetLoadPath("assets/color")
background = TLN_LoadBitmap("beach.png")
palette    = TLN_GetBitmapPalette(background)
sp	   = TLN_LoadSequencePack("beach.sqx")
sequence   = TLN_FindSequence(sp, "beach")

/* setup */
TLN_SetBGBitmap(background)
TLN_SetPaletteAnimation(0, palette, sequence, true)

/* main loop */
TLN_CreateWindow(NULL, 0)
TLN_DisableCRTEffect()
while(TLN_ProcessWindow())
	TLN_DrawFrame(0)
end

TLN_DeleteBitmap(background)
TLN_DeleteSequencePack(sp)
TLN_Deinit()
