load "guilib.ring"

oApp = new qApp {

	oView = new Qt3dwindow() 

	oWidget = new QWidget()	
	oWidget.installEventFilter( new QAllEvents(oWidget) { setCloseEvent("oApp.Quit()") } ) 

	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(NULL) 

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


 	oCylinder = new  QCylinderMesh(oRootEntity)
    	oCylinder.setRadius(1)
    	oCylinder.setRings(100)
    	oCylinder.setSlices(20)
	oCylinder.setLength(5)

	oCylinderTransform = new  QTransform(oCylinder)
	oCylinderTransform.setScale(2)
	oCylinderTransform.setTranslation(new QVector3D(1, 0, 3))

	oCylinderMaterial = new QPhongMaterial(oCylinder)
	oCylinderMaterial.setDiffuse(new QColor() {setRGB(200,100,100,100)})

	oCylinderEntity = new QEntity(oRootEntity)
	oCylinderEntity.addComponent(oCylinder)
	oCylinderEntity.addComponent(oCylinderMaterial)
	oCylinderEntity.addComponent(oCylinderTransform)
 
	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Using Qt3D - Cylinder") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}

	 
