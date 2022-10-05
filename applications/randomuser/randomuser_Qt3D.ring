#=====================================#
# Random User Application	
# Version using Qt3D
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"

cFirstName = ""
cLastName  = ""
cEmail     = ""
cImageFile = ""

C_IMAGEPATH = "file:///"+currentdir()+"/UserPhoto.jpg"

LoadUserData()

load "guilib.ring"

oApp = new QApp {

	StyleFusionBlack()

	oView = new Qt3dwindow() 

	oWidget = new QWidget()	

	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(oContainer) 

	oView.defaultframegraph().setclearcolor(
			new QColor() { setRGB(0,0,0,255) }
	)

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
	oTextureLoader.setSource(new QUrl(C_IMAGEPATH) )
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
	oTextTransform.setTranslation(new QVector3D(-7.5, -2, -4))

	oTextMaterial = new QPhongMaterial(oTextEntity);
	oTextMaterial.setDiffuse(new QColor() {setRGB(0,0,255,255)})
	
	oTextEntity.addComponent(oTextMesh)
	oTextEntity.addComponent(oTextTransform)
	oTextEntity.addComponent(oTextMaterial)

	oTextEntity2 = new QEntity(oRootEntity)

	oTextMesh2 = new  QExtrudedTextMesh(oTextEntity2) {
		setText("Email: " + cEmail)
	}

	oTextTransform2 = new  QTransform(oTextEntity2)
	oTextTransform2.setScale(1.5)
	oTextTransform2.setTranslation(new QVector3D(-15, -5, -4))

	oTextMaterial2 = new QPhongMaterial(oTextEntity2);
	oTextMaterial2.setDiffuse(new QColor() {setRGB(0,255,255,255)})
	
	oTextEntity2.addComponent(oTextMesh2)
	oTextEntity2.addComponent(oTextTransform2)
	oTextEntity2.addComponent(oTextMaterial2)

	oView.setRootEntity(oRootEntity)


	oNewUserDataButton = new QPushButton(oWidget) {
		setText("New User Data")
		setClickEvent("GetUserData()")
		setMinimumHeight(50)
		setStyleSheet("color:black;font-size:14pt;")
	}
	oCloseButton = new QPushButton(oWidget) {
		setText("Close Application")
		setClickEvent("CloseApplication()")
		setMinimumHeight(50)
		setStyleSheet("color:black;font-size:14pt;")
	}

	oLayout = new QVBoxLayout()
	oLayout.AddWidget(oContainer)
	oLayout.AddWidget(oNewUserDataButton)
	oLayout.AddWidget(oCloseButton)

	oWidget { 
		setwindowtitle("Random User - Using Qt3D") 
		setWinIcon(self, "images/appicon.png")
		setStyleSheet("background-color: gray")
		resize(800,600)
		setLayout(oLayout) 
		showMaximized() 
	}

	exec()
}

func GetUserData	

	LoadUserData()

	oTextMesh.setText(cFirstName + " " + cLastName)
	oTextMesh2.setText("Email: " + cEmail)

	oTextureLoader = new  QTextureLoader(oCube);
	oTextureLoader.setSource(new QUrl(C_IMAGEPATH) )
	oCubeMaterial.setTexture(oTextureLoader)

func LoadUserData

	cData= download("https://randomuser.me/api")
		
	aList= JSON2List(cData)
			
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cImageFile = aList[:Results][1][:picture][:large]
	
	write("UserPhoto.jpg",download(cImageFile))
	

func CloseApplication 

	oApp.Quit()
