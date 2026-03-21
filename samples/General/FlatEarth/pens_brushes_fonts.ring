# Pens, Brushes & Fonts
# Pens, Brushes & Fonts | الأقلام، الفرش والخطوط | Stylos, Pinceaux & Polices

### ── Pens ───────────────────────────────────────────────────────────────────

penNone      = new qPen() { setStyle(0) }
penWhite     = new qPen() { setColor(colorWhite)     setWidth(1) }
penAntEdge   = new qPen() { setColor(colorAntEdge)   setWidth(4) }
penOcean     = new qPen() { setColor(colorOcean)     setWidth(1) }
penLand      = new qPen() { setColor(colorLandEdge)  setWidth(1) }
penGreenland = new qPen() { setColor(colorGreenland) setWidth(1) }
penArctic    = new qPen() { setColor(colorArctic)    setWidth(2) }
penNPole     = new qPen() { setColor(colorNPole)     setWidth(1) }
penOrbitSun  = new qPen() { setColor(colorOrbitSun)  setWidth(1) }
penOrbitMoon = new qPen() { setColor(colorOrbitMoon) setWidth(1) }
penSunEdge   = new qPen() { setColor(colorSunEdge)   setWidth(2) }
penSunRay    = new qPen() { setColor(colorSunRay)    setWidth(2) }
penSunLbl    = new qPen() { setColor(colorSunLbl)    setWidth(1) }
penMoonEdge  = new qPen() { setColor(colorMoonEdge)  setWidth(1) }
penMoonLbl   = new qPen() { setColor(colorMoonLbl)   setWidth(1) }
penContLbl   = new qPen() { setColor(colorContLbl)   setWidth(1) }
penNPoleLbl  = new qPen() { setColor(colorNPoleLbl)  setWidth(1) }
penAntLbl    = new qPen() { setColor(colorAntLbl)    setWidth(1) }
penTitleTxt  = new qPen() { setColor(colorTitleTxt)  setWidth(1) }
penSubTxt    = new qPen() { setColor(colorSubTxt)    setWidth(1) }

### ── Brushes ────────────────────────────────────────────────────────────────

brushEmpty     = new qBrush() { setStyle(0) }
brushAntarct   = new qBrush() { setStyle(1) setColor(colorAntarct)   }
brushOcean     = new qBrush() { setStyle(1) setColor(colorOcean)     }
brushLand      = new qBrush() { setStyle(1) setColor(colorLand)      }
brushGreenland = new qBrush() { setStyle(1) setColor(colorGreenland) }
brushArctic    = new qBrush() { setStyle(1) setColor(colorArctic)    }
brushNPole     = new qBrush() { setStyle(1) setColor(colorNPole)     }
brushSunGlow1  = new qBrush() { setStyle(1) setColor(colorSunGlow1)  }
brushSunGlow2  = new qBrush() { setStyle(1) setColor(colorSunGlow2)  }
brushSunBody   = new qBrush() { setStyle(1) setColor(colorSunBody)   }
brushMoonGlow  = new qBrush() { setStyle(1) setColor(colorMoonGlow)  }
brushMoonBody  = new qBrush() { setStyle(1) setColor(colorMoonBody)  }
brushMoonCrat  = new qBrush() { setStyle(1) setColor(colorMoonCrat)  }
brushDayZone1  = new qBrush() { setStyle(1) setColor(colorDayZone1)  }
brushDayZone2  = new qBrush() { setStyle(1) setColor(colorDayZone2)  }
brushTitleBg   = new qBrush() { setStyle(1) setColor(colorTitleBg)   }

### ── Fonts ──────────────────────────────────────────────────────────────────

fontLabel = new qFont("DejaVu Sans",  9, 50, False)
fontTitle = new qFont("DejaVu Sans", 11, 75, False)
fontSub   = new qFont("DejaVu Sans",  8, 50, True)
