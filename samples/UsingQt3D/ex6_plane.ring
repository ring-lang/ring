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


 	oPlane = new  QPlaneMesh(oRootEntity)
	oPlane.setHeight(5)
	oPlane.setWidth(5)
	oPlane.setmeshresolution(new qSize(10,10))

	oPlaneTransform = new  QTransform(oPlane)
	oPlaneTransform.setScale(2)
	oPlaneTransform.setTranslation(new QVector3D(0, -4, 4))

	oPlaneMaterial = new QPhongMaterial(oPlane)
	oPlaneMaterial.setDiffuse(new QColor() {setRGB(200,100,100,100)})

	oPlaneEntity = new QEntity(oRootEntity)
	oPlaneEntity.addComponent(oPlane)
	oPlaneEntity.addComponent(oPlaneMaterial)
	oPlaneEntity.addComponent(oPlaneTransform)
 
	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Using Qt3D - Plane") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}

	 
