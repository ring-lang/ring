load "guilib.ring"

oApp = new qApp {

	oWidget = new QWidget()
	oWidget.installEventFilter( new QAllEvents(oWidget) { setCloseEvent("oApp.Quit()") } ) 

	oView = new Qt3DWindow() 
	oView.defaultFrameGraph().setClearColor(new QColor() {setRGB(0,0,0,255)})

	oContainer = oWidget.createWindowContainer(oView,oWidget,0)

	oRootEntity = new QEntity(oContainer) 

	oInput = new QInputAspect(oRootEntity)
        oView.registerAspect(oInput)

	oCameraEntity = oView.Camera()

	oCameraEntity.lens().setPerspectiveProjection(45.0, 16.0/9.0, 0.1, 1000)
  	oCameraEntity.setPosition(new QVector3D(-13.34, -6.43, 16.47))
    	oCameraEntity.setUpVector(new QVector3D(0.02, 0, 1))
    	oCameraEntity.setViewCenter(new QVector3D(-13.34, 17.05, 15.42))	

	oCameraController = new  QFirstPersonCameraController(oRootEntity)
   	oCameraController.setCamera(oCameraEntity)
	oCameraController.setEnabled(False)

	oLongRoomEntity = new QEntity(oRootEntity)

	oLongRoomModel = new QMesh(oLongRoomEntity)

	oLongRoomModel.setSource(new qURL("file:///"+CurrentDir()+"/assets/model/Long_Room.obj") ) 

	oLongRoomTransform = new  QTransform(oLongRoomEntity)
	oLongRoomTransform.setScale(1)
	oLongRoomTransform.setTranslation(new QVector3D(5, 0, 15))

	oLongRoomLoader = new  QTextureLoader(oLongRoomModel)
	oLongRoomMaterial = new QTextureMaterial(oLongRoomModel)
	oLongRoomLoader.setSource(new QUrl("file:///"+currentdir()+"/assets/texture/croc.jpg") )
	oLongRoomMaterial.setTexture(oLongRoomLoader)

	oLongRoomEntity.addComponent(oLongRoomModel)
	oLongRoomEntity.addComponent(oLongRoomMaterial)
	oLongRoomEntity.addComponent(oLongRoomTransform)

	oTableEntity = new QEntity(oRootEntity)

	oTableModel = new QMesh(oTableEntity)
	oTableModel.setSource(new qURL("file:///"+CurrentDir()+"/assets/model/Reception_Table.obj") ) 

	oTableTransform = new  QTransform(oTableEntity)
	oTableTransform.setScale(0.3)
	oTableTransform.setTranslation(new QVector3D(5, 0, 15))
	oQ = new QQuaternion(0,0,0,0)
	oTableTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), -180))

	oTableModelMaterial = new QPhongMaterial(oTableEntity)
	oTableModelMaterial.setDiffuse(new QColor() {setRGB(255,255,255,255)})

	oTableEntity.addComponent(oTableModel)
	oTableEntity.addComponent(oTableModelmaterial)
	oTableEntity.addComponent(oTableTransform)

	oFirstLightEntity = new QEntity(oRootEntity)

        oFirstLight = new QPointLight(oFirstLightEntity)
	oFirstLight.setColor(new qColor() { setRGB(128,128,128,128) })
	oFirstLight.setIntensity(1)

	oFirstLightTransform = new QTransform(oFirstLightEntity)
	oFirstLightTransform.setTranslation(new QVector3D(5, 0, 20))

	oFirstLightEntity.addComponent(oFirstLight)
	oFirstLightEntity.addComponent(oFirstLightTransform)

	aCats = list(5)
	for n = 1 to 5
		v = n * 0.1
		aCats[n] = []
		aCats[n][:oCatModelEntity] = new QEntity(oRootEntity)
		aCats[n][:oCatModel] = new QMesh(aCats[n][:oCatModelEntity])
		aCats[n][:oCatModel].setSource(new qURL("file:///"+CurrentDir()+"/assets/model/Lucky_Cat.obj") ) 
		aCats[n][:oCatModelMaterial] = new QPhongMaterial(aCats[n][:oCatModel])
		aCats[n][:oCatModelMaterial].setDiffuse(new QColor() {setRGB(255,255,255,255)})
		aCats[n][:oCatModelTransform] = new  QTransform(aCats[n][:oCatModelEntity])
		aCats[n][:oCatModelTransform].setScale(0.01)
		aCats[n][:oCatModelTransform].setTranslation(new QVector3D(-5*(v+v), 1, 15.2))
		oQ = new QQuaternion(0,0,0,0)
		aCats[n][:oCatModelTransform].setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 180))
		aCats[n][:oCatModelEntity].addComponent(aCats[n][:oCatModel])
		aCats[n][:oCatModelEntity].addComponent(aCats[n][:oCatModelmaterial])
		aCats[n][:oCatModelEntity].addComponent(aCats[n][:oCatModelTransform])
	next

	oSecondLightEntity = new QEntity(oRootEntity)

        oSecondLight = new QPointLight(oSecondLightEntity)
	oSecondLight.setColor(new qColor() { setRGB(255,255,255,255) })
	oSecondLight.setIntensity(1)

	oSecondLightTransform = new QTransform(oSecondLightEntity)
	oSecondLightTransform.setTranslation(new QVector3D(-5, 1, 15.5))

	oSecondLightEntity.addComponent(oSecondLight)
	oSecondLightEntity.addComponent(oSecondLightTransform)

	oRobotEntity = new QEntity(oRootEntity)

	oRobotModel = new QMesh(oRobotEntity)
	oRobotModel.setSource(new qURL("file:///"+CurrentDir()+"/assets/model/Fat_Robot.obj") ) 
	oRobotTransform = new  QTransform(oRobotEntity)
	oRobotTransform.setScale(0.006)
	
	robotX = -15
	robotY = -2
	robotZ = 15

	oRobotTransform.setTranslation(new QVector3D(-15, -2, 15))
	oQ = new QQuaternion(0,0,0,0)
	oRobotTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 170))

	oRobotMaterial = new QPhongMaterial(oRobotEntity)
	oRobotMaterial.setDiffuse(new QColor() {setRGB(128,128,128,255)})

	oRobotEntity.addComponent(oRobotModel)
	oRobotEntity.addComponent(oRobotTransform)
	oRobotEntity.addComponent(oRobotMaterial)

	oView.setRootEntity(oRootEntity)

	oWidget { 
		setwindowtitle("Using Qt3D - Scene") 
		showfullscreen() 
	}

	oContainer.resize(oWidget.width(),oWidget.height())

        oFilter = new QAllEvents(oView)
        oFilter.setKeyPressEvent("pKeyPress()")
        oView.installeventfilter(oFilter)
	oContainer.setfocus(0)

	exec()

}

func pKeyPress

	nKey 	= oFilter.getKeyCode()
	nSpeed 	= 0.1
	cX 	= oCameraEntity.position().x()
	CY 	= oCameraEntity.position().y()
	cZ 	= oCameraEntity.position().z()
	cVCx 	= oCameraEntity.viewCenter().x()
	cVCy 	= oCameraEntity.viewCenter().y()
	cVCz 	= oCameraEntity.viewCenter().z()

	switch nKey
		on Qt_Key_Right
			if cX < 4.8
				robotX+= nSpeed
			  	oCameraEntity.setPosition(new QVector3D(cX+0.1, cY, cZ))
			    	oCameraEntity.setViewCenter(new QVector3D(cVCx+nSpeed, cVCy, cVCz))	
				oRobotTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 170))
			ok
		on Qt_Key_Left
			if cX > - 13.8
				robotX-= nSpeed
			  	oCameraEntity.setPosition(new QVector3D(cX-0.1, cY, cZ))
			    	oCameraEntity.setViewCenter(new QVector3D(cVCx-nSpeed, cVCy, cVCz))	
				oRobotTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 160))
			ok
		on Qt_Key_Down 
			if robotY > -3.5
				robotY-= nSpeed
			  	oCameraEntity.setPosition(new QVector3D(cX, cY, cZ))
				oRobotTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 190))
			ok
		on Qt_Key_Up
			if robotY < 2
				robotY+= nSpeed
			  	oCameraEntity.setPosition(new QVector3D(cX, cY, cZ))
				oRobotTransform.setRotation(oQ.fromAxisAndAngle(new QVector3D(0, 1, 1), 180))
			ok
		on Qt_Key_Escape
			oWidget.close()
	off

	oRobotTransform.setTranslation(new QVector3D(robotX, robotY, robotZ))
