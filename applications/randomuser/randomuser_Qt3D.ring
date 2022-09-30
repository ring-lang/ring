#=====================================#
# Random User Application	
# Another version using Qt3D
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"

cData= download("https://randomuser.me/api")
	
aList= JSON2List(cData)
		
cFirstName = aList[:Results][1][:name][:first]
cLastName  = aList[:Results][1][:name][:last]
cEmail     = aList[:Results][1][:email]
cGender    = aList[:Results][1][:gender]
cImageFile = aList[:Results][1][:picture][:large]

write("UserPhoto.jpg",download(cImageFile))

load "guilib.ring"

new qApp {

	oView = new Qt3dwindow() 

	oWidget = new QWidget()	 {
		setWinIcon(oWidget, "images/appicon.png")
	}
	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(oContainer) 

	oView.defaultframegraph().setclearcolor(new QColor() {setRGB(200,150,150,255)})

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

 	oCube = new  QCuboidMesh(oRootEntity) {
		setXextent(2)
		setYextent(2)
		setZextent(3)
	}

	oCubeTransform = new  QTransform(oCube)
	oCubeTransform.setScale(2)
	oCubeTransform.setTranslation(new QVector3D(0, 3, 4))

	oTextureLoader = new  QTextureLoader(oCube);
	oTextureLoader.setSource(new QUrl("file:///"+currentdir()+"/UserPhoto.jpg") )
	oCubeMaterial = new QTextureMaterial(oCube)
	oCubeMaterial.setTexture(oTextureLoader)

	oCubeEntity = new QEntity(oRootEntity)
	oCubeEntity.addComponent(oCube)
	oCubeEntity.addComponent(oCubeMaterial)
	oCubeEntity.addComponent(oCubeTransform)
 
	oTextEntity = new QEntity(oRootEntity)

	oTextMesh = new  QExtrudedTextMesh(oTextEntity) {
		setText(cFirstName + " " + cLastName)
	}

	oTextTransform = new  QTransform(oTextEntity)
	oTextTransform.setScale(2)
	oTextTransform.setTranslation(new QVector3D(-7.5, -4, 3))

	oTextMaterial = new QPhongMaterial(oTextEntity);
	oTextMaterial.setDiffuse(new QColor() {setRGB(0,0,255,255)})
	
	oTextEntity.addComponent(oTextMesh)
	oTextEntity.addComponent(oTextTransform)
	oTextEntity.addComponent(oTextMaterial)

	oView.setRootEntity(oRootEntity)

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)

	oWidget { 
		setwindowtitle("Random User - Using Qt3D") 
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}
	
