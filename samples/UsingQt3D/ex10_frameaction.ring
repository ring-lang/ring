load "guilib.ring"

oApp = new qApp {

	oView = new Qt3dwindow() 

	oWidget = new QWidget()	
	oWidget.installEventFilter( new QAllEvents(oWidget) { setCloseEvent("oApp.Quit()") } ) 

	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(oContainer) 

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
		setXextent(1)
		setYextent(1)
		setZextent(1)
	}

	oCubeTransform = new  QTransform(oCube)
	oCubeTransform.setScale(2)
	oCubeTransform.setTranslation(new QVector3D(-5, -5, -5))

	oTextureLoader = new  QTextureLoader(oCube);
	oTextureLoader.setSource(new QUrl("file:///"+currentdir()+"/assets/texture/gold.jpg") )
	oCubeMaterial = new QTextureMaterial(oCube)
	oCubeMaterial.setTexture(oTextureLoader)

	oCubeEntity = new QEntity(oRootEntity)
	oCubeEntity.addComponent(oCube)
	oCubeEntity.addComponent(oCubeMaterial)
	oCubeEntity.addComponent(oCubeTransform)
 
	nAngle=0	nSpeed=0.1
	oFrameAction = new qFrameAction(oRootEntity) {
		settriggeredevent("pEvent()")
	}

	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Using Qt3D - Frame Action") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}

func pEvent

	# Move the Cube
		oX = oCubeTransform.translation().x()
		oY = oCubeTransform.translation().y() 
		oZ = oCubeTransform.translation().z()
		if oX >= 4
			nSpeed=-0.1
		but oX <= -10
			nSpeed=0.1
		ok
		oCubeTransform.setTranslation(new QVector3D(oX+nSpeed, oY+nSpeed, oZ+nSpeed))

	# Rotate the Cube
		nAngle+=5  if nAngle=360  nAngle=0 ok
		oQ = new QQuaternion(0,0,0,0)
		oCubeTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 0), nAngle))
		
