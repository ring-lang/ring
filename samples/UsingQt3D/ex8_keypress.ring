load "guilib.ring"

oApp = new qApp {

	oView = new Qt3dwindow() 

	oWidget = new QWidget()	
	oWidget.installEventFilter( new QAllEvents(oWidget) { setCloseEvent("oApp.Quit()") } ) 

	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(NULL) 

        oFilter = new qallevents(oView)
        oFilter.setKeyPressEvent("pKeyPress()")
        oView.installeventfilter(oFilter)

	oInput = new QInputAspect(oRootEntity)
        oView.registerAspect(oInput)

	oCameraEntity = oView.Camera()

	oCameraEntity.lens().setPerspectiveProjection(45.0, 16.0/9.0, 0.1, 1000.0)
    	oCameraEntity.setPosition(new QVector3D(0, 0, 20.0))
    	oCameraEntity.setUpVector(new QVector3D(0, 1, 0))
    	oCameraEntity.setViewCenter(new QVector3D(0, 0, 0))	

	oLightEntity = new QEntity(oRootEntity)
        oLight = new QPointLight(oLightEntity)
	oLight.setColor(new QColor() { setRGB(255,255,255,255) })
	oLight.setIntensity(1)
	oLightEntity.addComponent(oLight)

	oLightTransform = new QTransform(oLightEntity)
	oLightTransform.setTranslation(oCameraEntity.position())
	oLightEntity.addComponent(oLightTransform)

 	oCamController = new  QFirstPersonCameraController(oRootEntity)
    	oCamController.setCamera(oCameraEntity)
	oCamController.setEnabled(False)

 	oCube = new  QCuboidMesh(oRootEntity) {
		setXextent(2)
		setYextent(2)
		setZextent(3)
	}

	oCubeTransform = new  QTransform(oCube)
	oCubeTransform.setScale(2)
	oCubeTransform.setTranslation(new QVector3D(3, 3, 3))

	oTextureLoader = new  QTextureLoader(oCube);
	oTextureLoader.setSource(new QUrl("file:///"+currentdir()+"/assets/texture/gold.jpg") )
	oCubeMaterial = new QTextureMaterial(oCube)
	oCubeMaterial.setTexture(oTextureLoader)

	oCubeEntity = new QEntity(oRootEntity)
	oCubeEntity.addComponent(oCube)
	oCubeEntity.addComponent(oCubeMaterial)
	oCubeEntity.addComponent(oCubeTransform)
 
	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Using Qt3D - Moving Cube using the Keyboard") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	oContainer.setfocus(0)

	exec()
}

func pKeyPress
	nKey = oFilter.getkeycode()
	oX = oCubeTransform.translation().x()
	oY = oCubeTransform.translation().y() 
	oZ = oCubeTransform.translation().z()
	switch nKey
		on Qt_Key_Right
			oX++
		on Qt_Key_Left
			oX--
		on Qt_Key_Up
			oY++
		on Qt_Key_Down
			oY--
	off
	oCubeTransform.setTranslation(new QVector3D(oX, oY, oZ))

	 
