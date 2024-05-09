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
    	oCameraEntity.setViewCenter(new QVector3D(0, 20, 0))	

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

	oModel = new qmesh(oRootEntity)
	oModel.setsource(new qURL("file:///"+currentdir()+"/assets/model/Robot.obj") ) 

	oModelTransform = new  QTransform(oModel)
	oModelTransform.setScale(0.2)
	oModelTransform.setTranslation(new QVector3D(0, 10, 10))

	oModelMaterial = new QPhongMaterial(oModel)
	oModelMaterial.setDiffuse(new QColor() {setRGB(0,100,0,0)})

	oModelEntity = new QEntity(oRootEntity)
	oModelEntity.addComponent(oModel)

	oLoader = new  QTextureLoader(oModel);
	oModelMaterial = new QTextureMaterial(oModel)
	oLoader.setSource(new QUrl("file:///"+currentdir()+"/assets/texture/gold.jpg") )
	oModelMaterial.setTexture(oLoader)

	oModelEntity.addComponent(oModelMaterial)
	oModelEntity.addComponent(oModelTransform)

	for n = 1 to 10

	 	oTorus = new  QTorusMesh(oRootEntity)
	    	oTorus.setRadius(1.0*n)
	    	oTorus.setMinorRadius(0.4*n)
	    	oTorus.setRings(100)
	    	oTorus.setSlices(20)
	
		oTorusTransform = new  QTransform(null)
		oTorusTransform.setScale(2)
		oTorusTransform.setTranslation(new QVector3D(5.0*n, 4.0*n, 0.0))
	
		oTorusMaterial = new QPhongMaterial(null);
		oTorusMaterial.setDiffuse(new QColor() {setRGB(200,100,100,100)})
	
		oTorusEntity = new QEntity(oRootEntity)
		oTorusEntity.addComponent(oTorus)
	
		oLoader = new  QTextureLoader(oTorus);
		oTorusMaterial = new QTextureMaterial(oTorus)
		oLoader.setSource(new QUrl("file:///"+currentdir()+"/assets/texture/gold.jpg") )
		oTorusMaterial.setTexture(oLoader)
	
		oTorusEntity.addComponent(oTorusMaterial)
		oTorusEntity.addComponent(oTorusTransform)
	next

	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Using Qt3D - Many Objects") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}

	 



