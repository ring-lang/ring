#ifndef RING_QT
#define RING_QT

extern "C" {
void ring_qt_start(RingState *pRingState);
}

RING_FUNC(ring_gui_start);
RING_FUNC(ring_gui_doevents);
RING_FUNC(ring_gui_end);
RING_FUNC(ring_gui_window) ;
RING_FUNC(ring_gui_newlabel) ;
RING_FUNC(ring_gui_newpixmap) ;
RING_FUNC(ring_gui_deletepixmap) ;
RING_FUNC(ring_gui_deletewindow) ;
RING_FUNC(ring_gui_setpixmap) ;
RING_FUNC(ring_gui_pixmapcopy) ;
RING_FUNC(ring_gui_setbtnpixmap) ;
RING_FUNC(ring_gui_setlabelcaption) ;
RING_FUNC(ring_gui_setlabelaligncenter) ;
RING_FUNC(ring_gui_newbtn) ;
RING_FUNC(ring_gui_setcaption) ;
RING_FUNC(ring_gui_setheight) ;
RING_FUNC(ring_gui_setwidth) ;
RING_FUNC(ring_gui_setpos) ;
RING_FUNC(ring_gui_newwindow);
RING_FUNC(ring_gui_childbutton);
RING_FUNC(ring_gui_setclickevent);
RING_FUNC(ring_gui_show);
RING_FUNC(ring_gui_showwindow);
RING_FUNC(ring_gui_closewindow);
RING_FUNC(ring_gui_newvboxlayout);
RING_FUNC(ring_gui_newhboxlayout);
RING_FUNC(ring_gui_vlayoutaddwidget);
RING_FUNC(ring_gui_vlayoutaddlayout);
RING_FUNC(ring_gui_hlayoutaddwidget);
RING_FUNC(ring_gui_hlayoutaddlayout);
RING_FUNC(ring_gui_setlayout);
RING_FUNC(ring_gui_setstylesheet);
RING_FUNC(ring_gui_newlineedit);
RING_FUNC(ring_gui_getlineeditvalue);

#endif
