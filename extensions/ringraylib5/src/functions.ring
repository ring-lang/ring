func RayLibColor r,b,g,a
	return GetColor( Bytes2Int(  Char(a) + Char(g) + Char(b) + Char(r) ) )

func Vector2 x,y
	oVector = new Vector2(x,y)
	return oVector

func Vector3 x,y,z
	oVector = new Vector3(x,y,z)
	return oVector

func Vector4 x,y,z,w
	oVector = new Vector4(x,y,z,w)
	return oVector

func Quaternion x,y,z,w
	oQuaternion = new Quaternion(x,y,z,w)
	return oQuaternion

func Matrix m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15
	oMatrix = new Matrix(m0, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15)
	return oMatrix

func Color r,g,b,a
	oColor = new Color(r,g,b,a)
	return oColor

func Rectangle x,y,width,height 
	oRectangle = new Rectangle(x,y,width,height)
	return oRectangle

func Image p1,p2,p3,p4,p5
	oImage = new Image(p1,p2,p3,p4,p5)
	return oImage

func Texture2D p1,p2,p3,p4,p5
	oTexture2D = new Texture2D(p1,p2,p3,p4,p5)
	return oTexture2D

func Texture p1,p2,p3,p4,p5
	return Texture2D(p1,p2,p3,p4,p5)

func NPatchInfo p1,p2,p3,p4,p5,p6,p7,p8,p9
	oNPatchInfo = new NPatchInfo(p1,p2,p3,p4,p5,p6,p7,p8,p9)
	return oNPatchInfo

func CharInfo p1,p2,p3,p4,p5,p6,p7,p8,p9
	oCharInfo = new CharInfo(p1,p2,p3,p4,p5,p6,p7,p8,p9)
	return oCharInfo

func Font p1,p2,p3,p4,p5,p6,p7,p8
	oSpriteFont = new SpriteFont(p1,p2,p3,p4,p5,p6,p7,p8)
	return oSpriteFont

func RenderTexture2D p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12
	oRenderTexture2D = new RenderTexture2D(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12)
	return oRenderTexture2D

func RenderTexture p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12
	oRenderTexture2D = new RenderTexture2D(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12)
	return oRenderTexture2D

func SpriteFont p1,p2,p3,p4,p5,p6,p7,p8
	oSpriteFont = new SpriteFont(p1,p2,p3,p4,p5,p6,p7,p8)
	return oSpriteFont

func Camera3D p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11 
	oCamera = new Camera3D(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11)
	return oCamera

func Mesh p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14
	oMesh = new Mesh(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14)
	return oMesh

func Shader p1
	oShader = new Shader(p1)
	return oShader

func Material p1,p2
	oMaterial = new Material(p1,p2)
	return oMaterial

func Transform p1,p2,p3,p4,p5,p6,p7,p8,p9
	oTransform = new Transform(p1,p2,p3,p4,p5,p6,p7,p8,p9)
	return oTransform

func BoneInfo p1
	oBoneInfo = new BoneInfo(p1)
	return oBoneInfo

func Model 
	oModel = new Model()
	return oModel

func ModelAnimation p1,p2,p3
	oModelAnimation = new ModelAnimation(p1,p2,p3)
	return oModelAnimation

func Ray p1,p2,p3,p4,p5,p6
	oRay = new Ray(p1,p2,p3,p4,p5,p6)
	return oRay

func RayhitInfo p1,p2,p3,p4,p5,p6,p7,p8
	oRayHitInfo = new RayHitInfo(p1,p2,p3,p4,p5,p6,p7,p8)
	return oRayHitInfo

func BoundingBox p1,p2,p3,p4,p5,p6
	oBox = new BoundingBox(p1,p2,p3,p4,p5,p6)
	return oBox

func Wave p1,p2,p3,p4,p5
	oWave = new Wave(p1,p2,p3,p4,p5)
	return oWave

func AudioStream p1,p2,p3,p4,p5,p6
	oAudioStream = new AudioStream(p1,p2,p3,p4,p5,p6)
	return oAudioStream

func VrDeviceInfo p1,p2,p3,p4,p5,p6,p7,p8
	oVrDeviceInfo = new VrDeviceInfo(p1,p2,p3,p4,p5,p6,p7,p8)
	return oVrDeviceInfo

func RayLib_PrepareKey vKey
	if isNumber(vKey)
		return vKey
	but isString(vKey)
		return ASCII(vKey[1])
	else 
		raise("Bad parameter type - RayLib_PrepareKey() function")
	ok

func isKeyDown vKey
	return isKeyDown_2(RayLib_PrepareKey(vKey))

func IsKeyPressed vKey
	return IsKeyPressed_2(RayLib_PrepareKey(vKey))

func IsKeyReleased vKey
	return IsKeyReleased_2(RayLib_PrepareKey(vKey))

func IsKeyUp vKey
	return IsKeyUp_2(RayLib_PrepareKey(vKey))

func SetExitKey vKey
	return SetExitKey_2(RayLib_PrepareKey(vKey))

# Get Pointer Data 
func GPData vData 
	if isObject(vData)
		return vData.Data()
	ok
	return vData

# Update Object Data 
func UOData vData 
	if isObject(vData)
		vData.refresh()
	ok

func BeginMode2D camera
	return BeginMode2D_2(GPData(Camera))

func BeginMode3D camera
	return BeginMode3D_2(GPData(Camera))

func GetMouseRay mousePosition,camera
	return GetMouseRay_2(GPData(mousePosition),GPData(Camera))

func GetWorldToScreen position,camera
	return GetWorldToScreen_2(GPData(position),GPData(Camera))

func GetCameraMatrix camera
	return GetCameraMatrix_2(GPData(Camera))

func SetCameraMode camera,mode
	return UpdateCamera_2(GPData(camera),mode)

func UpdateCamera camera
	if isObject(camera)
		UpdateCamera_2(camera.Data(),0)
		camera.refresh()
	else
		return UpdateCamera_2(camera,0)
	ok
	
func DrawBillboard camera,texture,center,size,tint
	return DrawBillboard_2(GPData(camera),GPData(texture),GPData(center),size,tint)

func DrawBillboardRec camera,texture,sourceRec,center,size,tint
	return DrawBillboardRec_2(GPData(camera),GPData(texture),GPData(sourceRec),GPData(center),size,GPData(tint))

func UpdateVrTracking camera
	return UpdateVrTracking_2(GPData(camera))

func DrawPixelV position, color
	return DrawPixelV_2(GPData(position),GPData(color))

func DrawLineV startPos, endPos, color
	return DrawLineV_2(GPData(startPos),GPData(endPos),GPData(color))

func DrawLineEx startPos, endPos, thick, color
	return DrawLineEx_2(GPData(startPos),GPData(endPos),thick,GPData(color))

func DrawLineBezier startPos, endPos, thick, color
	return DrawLineBezier_2(GPData(startPos), GPData(endPos), thick, GPData(color))

func DrawLineStrip points, numPoints, color
	return DrawLineStrip_2(points, numPoints, color)

func DrawCircleSector center,radius,startAngle,endAngle,segments,color
	return DrawCircleSector_2(GPData(center),radius,startAngle,endAngle,segments,GPData(color))

func DrawCircleSectorLines center,radius,startAngle,endAngle,segments,color
	return DrawCircleSectorLines_2(GPData(center),radius,startAngle,endAngle,segments,GPData(color))

func DrawCircleV center, radius, color
	return DrawCircleV_2(GPData(Center), radius, GPData(color))

func DrawRing center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	return DrawRing_2(GPData(center), innerRadius, outerRadius, startAngle, endAngle, segments, GPData(color))

func DrawRingLines center, innerRadius, outerRadius, startAngle, endAngle, segments, color
	return DrawRingLines_2(GPData(center), innerRadius, outerRadius, startAngle, endAngle, segments, GPData(color))

func DrawRectangleV position, size, color
	return DrawRectangleV_2(GPData(position), GPData(size), GPData(color))

func DrawTriangle v1, v2, v3, color
	return DrawTriangle_2(GPData(v1), GPData(v2), GPData(v3), GPData(color))

func DrawTriangleLines v1, v2, v3, color
	return DrawTriangleLines_2(GPData(v1), GPData(v2), GPData(v3), GPData(color))

func DrawTriangleFan points, numPoints, color
	return DrawTriangleFan_2(points, numPoints, GPData(color))

func DrawPoly center, sides, radius, rotation, color
	return DrawPoly_2(GPData(center), sides, radius, rotation, GPData(color))

func CheckCollisionCircles center1, radius1, center2, radius2
	return CheckCollisionCircles_2(GPData(center1), radius1, GPData(center2), radius2)

func CheckCollisionCircleRec center, radius, rec
	return CheckCollisionCircleRec_2(GPData(center), radius, GPData(rec))

func CheckCollisionPointRec point, rec
	return CheckCollisionPointRec_2(GPData(point), GPData(rec))

func CheckCollisionPointCircle point, center, radius
	return CheckCollisionPointCircle_2(GPData(point), GPData(center), radius)

func CheckCollisionPointTriangle point, p1, p2, p3
	return CheckCollisionPointTriangle_2(GPData(point), GPData(p1), GPData(p2), GPData(p3))

func ColorFromHSV hsv
	return ColorFromHSV_2(GPData(hsv))

func DrawLine3D startPos, endPos, color
	return DrawLine3D_2(GPData(startPos), GPData(endPos), GPData(color))

func DrawCircle3D center, radius, rotationAxis, rotationAngle, color
	return DrawCircle3D_2(GPData(center),radius, GPData(rotationAxis), rotationAngle, GPData(color))

func DrawCube position, width,  height, length, color
	return DrawCube_2(GPData(position), width,  height, length, GPData(color))

func DrawCubeV position, size, color
	return DrawCubeV_2(GPData(position), GPData(size), GPData(color))

func DrawCubeWires position, width, height, length, color
	return DrawCubeWires_2(GPData(position), width, height, length, GPData(color))

func DrawCubeWiresV position, size, color
	return DrawCubeWiresV_2(GPData(position), GPData(size), GPData(color))

func DrawSphere centerPos, radius, color
	return DrawSphere_2(GPData(centerPos), radius, GPData(color))

func DrawSphereEx centerPos, radius, rings, slices, color
	return DrawSphereEx_2(GPData(centerPos), radius, rings, slices, GPData(color))

func DrawSphereWires centerPos, radius, rings, slices, color
	return DrawSphereWires_2(GPData(centerPos), radius, rings, slices, GPData(color))

func DrawCylinder position, radiusTop, radiusBottom, height,  slices, color
	return DrawCylinder_2(GPData(position), radiusTop, radiusBottom, height,  slices, GPData(color))

func DrawCylinderWires position, radiusTop, radiusBottom, height, slices, color
	return DrawCylinderWires_2(GPData(position), radiusTop, radiusBottom, height, slices, GPData(color))

func DrawPlane centerPos, size, color
	return DrawPlane_2(GPData(centerPos), GPData(size), GPData(color))

func DrawGizmo position
	return DrawGizmo_2(GPData(position))

func GenMeshHeightmap heightmap, size
	return GenMeshHeightmap_2(GPData(heightmap), GPData(size))

func GenMeshCubicmap cubicmap, cubeSize
	return GenMeshCubicmap_2(GPData(cubicmap), GPData(cubeSize))

func DrawModel model,  position, scale,  tint
	return DrawModel_2(GPData(model), GPData(position), scale,  GPData(tint))

func DrawModelEx model,  position, rotationAxis,  rotationAngle, scale,  tint
	return DrawModelEx_2(GPData(model),  GPData(position), GPData(rotationAxis),  rotationAngle, GPData(scale),  GPData(tint))

func DrawModelWires model, position, scale, tint
	return DrawModelWires_2(GPData(model), GPData(position), scale, GPData(tint))

func DrawModelWiresEx model,  position, rotationAxis,  rotationAngle, scale,  tint
	return DrawModelWiresEx_2(GPData(model),  GPData(position), GPData(rotationAxis),  rotationAngle, GPData(scale),  GPData(tint))

func CheckCollisionSpheres centerA,  radiusA, centerB,  radiusB
	return CheckCollisionSpheres_2(GPData(centerA),  radiusA, GPData(centerB),  radiusB)

func CheckCollisionBoxSphere box,  centerSphere,  radiusSphere
	return CheckCollisionBoxSphere_2(GPData(box), GPData(centerSphere),  radiusSphere)

func CheckCollisionRaySphere ray,  spherePosition,  sphereRadius
	return CheckCollisionRaySphere_2(GPData(ray),  GPData(spherePosition),  sphereRadius)

func CheckCollisionRaySphereEx ray, spherePosition, sphereRadius, collisionPoint
	return CheckCollisionRaySphereEx_2(GPData(ray), GPData(spherePosition), sphereRadius, GPData(collisionPoint))

func GetCollisionRayTriangle ray, p1, p2, p3
	return GetCollisionRayTriangle_2(GPData(ray), GPData(p1), GPData(p2), GPData(p3))

func DrawRectangleRec rec, color
	return DrawRectangleRec_2(GPData(rec), GPData(color))

func DrawRectanglePro rec, origin, rotation, color
	return DrawRectanglePro_2(GPData(rec), GPData(origin), rotation, GPData(color))

func DrawRectangleGradientEx rec,  col1,  col2,  col3,  col4
	return DrawRectangleGradientEx_2(GPData(rec),  col1,  col2,  col3,  col4)

func DrawRectangleLinesEx rec,  lineThick, color
	return DrawRectangleLinesEx_2(GPData(rec),  lineThick, GPData(color))

func DrawRectangleRounded rec,  roundness,  segments,  color
	return DrawRectangleRounded_2(GPData(rec),  roundness,  segments,  GPData(color))

func DrawRectangleRoundedLines rec,  roundness,  segments,  lineThick, color
	return DrawRectangleRoundedLines_2(GPData(rec),  roundness,  segments,  lineThick, GPData(color))

func SetShapesTexture texture, source
	return SetShapesTexture_2(GPData(texture), GPData(source))

func CheckCollisionRecs rec1,  rec2
	return CheckCollisionRecs_2(GPData(rec1), GPData(rec2))

func GetCollisionRec rec1, rec2
	oRectangle = new Rectangle
	oRectangle.setData( GetCollisionRec_2(GPData(rec1), GPData(rec2)) )
	return oRectangle

func ImageCrop image, crop
	oImage = ImageCrop_2(GPData(image), GPData(crop))
	UOData(image)
	return oImage

func ImageDraw dst, src,  srcRec,  dstRec
	ImageDraw_2(GPData(dst), GPData(src),  GPData(srcRec),  GPData(dstRec))
	UOData(dst)
	UOData(src)
	return

func ImageDrawRectangle dst, rec, color
	return ImageDrawRectangle_2(GPData(dst), GPData(rec), GPData(color))

func ImageDrawRectangleLines dst, rec, thick, color
	return ImageDrawRectangleLines_2(GPData(dst), GPData(rec), thick, GPData(color))

func DrawTextureRec texture, sourceRec, position, tint
	return DrawTextureRec_2(GPData(texture), GPData(sourceRec), GPData(position), GPData(tint))

func DrawTextureQuad texture,  tiling, offset,  quad,  tint
	return DrawTextureQuad_2(GPData(texture), GPData(tiling), GPData(offset), GPData(quad),  GPData(tint))

func DrawTexturePro texture, sourceRec,  destRec,  origin, rotation, tint
	return DrawTexturePro_2(GPData(texture), GPData(sourceRec),  GPData(destRec), GPData(origin), rotation, GPData(tint))

func DrawTextureNPatch texture,  nPatchInfo, destRec,  origin,  rotation, tint
	return DrawTextureNPatch_2(GPData(texture),  nPatchInfo, GPData(destRec), GPData(origin),  rotation, GPData(tint))

func DrawTextRec font,  text,  rec,  fontSize,  spacing,  wordWrap,  tint
	return DrawTextRec_2(GPData(font),  text, GPData(rec),  fontSize,  spacing,  wordWrap,  GPData(tint))

func DrawTextRecEx font, text,  rec, fontSize, spacing, wordWrap, tint, selectStart, selectLength, selectText, selectBack
	return DrawTextRecEx_2(GPData(font), text, GPData(rec), fontSize, spacing, wordWrap, GPData(tint), selectStart, selectLength, selectText, selectBack)

func GuiWindowBox bounds, text
	return GuiWindowBox_2(GPData(bounds), text)

func GuiGroupBox bounds, text
	return GuiGroupBox_2(GPData(bounds), text)

func GuiLine bounds, text
	return GuiLine_2(GPData(bounds), text)

func GuiPanel bounds
	return GuiPanel_2(GPData(bounds))

func GuiScrollPanel bounds, content, scroll
	return GuiScrollPanel_2(GPData(bounds), GPData(content), GPData(scroll))

func GuiLabel bounds, text
	return GuiLabel_2(GPData(bounds), text)

func GuiButton bounds, text
	return GuiButton_2(GPData(bounds), text)

func GuiLabelButton bounds, text
	return GuiLabelButton_2(GPData(bounds), text)

func GuiImageButton bounds,  texture
	return GuiImageButton_2(GPData(bounds),  GPData(texture))

func GuiImageButtonEx bounds, texture, texSource, text
	return GuiImageButtonEx_2(GPData(bounds), GPData(texture), GPData(texSource), text)

func GuiToggle bounds, text, active
	return GuiToggle_2(GPData(bounds), text, active)

func GuiToggleGroup bounds, text, active
	return GuiToggleGroup_2(GPData(bounds), text, active)

func GuiCheckBox bounds, text, checked
	return GuiCheckBox_2(GPData(bounds), text, checked)

func GuiComboBox bounds, text, active
	return GuiComboBox_2(GPData(bounds), text, active)

func GuiDropdownBox bounds, text, active, editMode
	return GuiDropdownBox_2(GPData(bounds), text, active, editMode)

func GuiSpinner bounds, value, minValue, maxValue, editMode
	return GuiSpinner_2(GPData(bounds), value, minValue, maxValue, editMode)

func GuiValueBox bounds, value, minValue, maxValue, editMode
	return GuiValueBox_2(GPData(bounds), value, minValue, maxValue, editMode)

func GuiTextBox bounds, text, textSize, editMode
	return GuiTextBox_2(GPData(bounds), text, textSize, editMode)

func GuiTextBoxMulti bounds, text, textSize, editMode
	return GuiTextBoxMulti_2(GPData(bounds), text, textSize, editMode)

func GuiSlider bounds, text, value, minValue, maxValue, showValue
	return GuiSlider_2(GPData(bounds), text, value, minValue, maxValue, showValue)

func GuiSliderBar bounds, text, value, minValue, maxValue, showValue
	return GuiSliderBar_2(GPData(bounds), text, value, minValue, maxValue, showValue)

func GuiProgressBar bounds, text, value, minValue, maxValue, showValue
	return GuiProgressBar_2(GPData(bounds), text, value, minValue, maxValue, showValue)

func GuiStatusBar bounds, text
	return GuiStatusBar_2(GPData(bounds), text)

func GuiDummyRec bounds, text
	return GuiDummyRec_2(GPData(bounds), text)

func GuiScrollBar bounds, value, minValue, maxValue
	return GuiScrollBar_2(GPData(bounds), value, minValue, maxValue)

func GuiGrid bounds, spacing, subdivs
	return GuiGrid_2(GPData(bounds), spacing, subdivs)

func GuiListView bounds, text, active, scrollIndex, editMode
	return GuiListView_2(GPData(bounds), text, active, scrollIndex, editMode)

func GuiListViewEx bounds, text, count, enabled, active, focus, scrollIndex, editMode
	return GuiListViewEx_2(GPData(bounds), text, count, enabled, active, focus, scrollIndex, editMode)

func GuiMessageBox bounds, windowTitle, message, buttons
 	return GuiMessageBox_2(GPData(bounds), windowTitle, message, buttons)

func GuiTextInputBox bounds, windowTitle, message, text, buttons
	return GuiTextInputBox_2(GPData(bounds), windowTitle, message, text, buttons)

func GuiColorPicker bounds, color
	return GuiColorPicker_2(GPData(bounds), color)

func GetTouchPosition index
	oVector = new Vector2(0,0)
	oVector.setData(GetTouchPosition_2(index))
	return  oVector

func DrawRay ray, color 
	return DrawRay_2(GPData(ray),GPData(color))

func CheckCollisionRayBox ray, box
	return CheckCollisionRayBox_2(GPData(ray),GPData(box))

func LoadTextureFromImage p1
	oTexture = new Texture2D
	oTexture.setData(LoadTextureFromImage_2(GPData(p1)))
	return oTexture

func DrawTextureEx texture, position, rotation, scale, tint
	return DrawTextureEx_2( GPData(texture) , GPData(position), rotation, scale, GPData(tint ))

func LoadImage fileName
	oImage = new Image
	oImage.setData(LoadImage_2(fileName))
	return oImage

func LoadImageEx pixels, width, height
	oImage = new Image 
	oImage.setData(LoadImageEx_2(pixels, width, height))
	return oImage

func LoadImagePro data, width, height, format
	oImage = new Image 
	oImage.setData(LoadImagePro_2(data, width, height, format))
	return oImage

func LoadImageRaw(fileName, width, height, format, headerSize)
	oImage = new Image 
	oImage.setData(LoadImageRaw_2(fileName, width, height, format, headerSize))
	return oImage

func ImageFlipVertical image
	ImageFlipVertical_2(GPData(image))
	UOData(image)
	return 

func ImageFlipHorizontal image
	ImageFlipHorizontal_2(GPData(image))
	UOData(image)
	return 

func ImageRotateCW image
	ImageRotateCW_2(GPData(image))
	UOData(image)
	return

func ImageRotateCCW image
	ImageRotateCCW_2(GPData(image))
	UOData(image)
	return

func ImageColorTint image, color
	ImageColorTint_2(GPData(image), GPData(color))
	UOData(image)
	return

func ImageColorInvert image
	ImageColorInvert_2(GPData(image))
	UOData(image)
	return

func ImageColorGrayscale image
	ImageColorGrayscale_2(GPData(image))
	UOData(image)
	return

func ImageColorContrast image, contrast
	ImageColorContrast_2(GPData(image), contrast)
	UOData(image)
	return

func ImageColorBrightness image, brightness
	ImageColorBrightness_2(GPData(image), brightness)
	UOData(image)
	return

func ImageColorReplace image, color, replace
	ImageColorReplace_2(GPData(image), GPData(color), GPData(replace))
	UOData(image)
	return 

func UnloadImage image
	return UnloadImage_2(GPData(image))

func UnloadTexture texture
	return UnloadTexture_2(GPData(texture))

func ImageResize image, newWidth, newHeight
	ImageResize_2(GPData(image), newWidth, newHeight)
	UOData(image)
	return 

func DrawTexture texture, posX, posY, tint
	return DrawTexture_2( GPData(texture),  posX,  posY, GPData(tint) )

func ImageDrawText dst, position, text, fontSize, color
	ImageDrawText_2(GPData(dst), GPData(position), text, fontSize, GPData(color))
	UOData(dst)
	return

func ImageDrawTextEx dst, position, font, text, fontSize, spacing, color
	ImageDrawTextEx_2(GPData(dst), GPData(position), GPData(font), text, fontSize, spacing, GPData(color))
	UOData(dst)
	return

func LoadFont fileName
	oFont = new Font 
	oFont.setData(LoadFont_2(fileName))
	return oFont

func UnloadFont font
	return UnloadFont_2(GPData(font))

func GetMousePosition
	oVector = new Vector2
	oVector.setData( GetMousePosition_2()  )
	return oVector

func LoadTexture fileName
	oTexture2D = new Texture2D
	oTexture2D.setData( LoadTexture_2(fileName) )
	return oTexture2D

func setmodelmaterialtexture oModel,nIndex,nMap,oTexture
	return setmodelmaterialtexture_2(GPData(oModel),nIndex,nMap,GPData(oTexture))

func setmodelmaterialshader oModel,nIndex,oShader
	return setmodelmaterialshader_2(GPData(oModel),nIndex,GPData(oShader))

func GetImageData image
	return GetImageData_2(GPData(image))

func LoadImageColors image
	return LoadImageColors_2(GPData(image))


func LoadWave fileName
	oWave = new Wave
	oWave.setData( LoadWave_2(fileName) )
	return oWave

func LoadWaveEx data, sampleCount, sampleRate, sampleSize, channels
	oWave = new Wave
	oWave.setData( LoadWaveEx_2(data, sampleCount, sampleRate, sampleSize, channels) )
	return oWave

func LoadSound fileName
	return LoadSound_2(fileName)

func UpdateSound sound, data, samplesCount
	return UpdateSound_2(GPData(sound), data, samplesCount)

func UnloadWave wave
	return UnloadWave_2(GPData(wave))

func UnloadSound sound
	return UnloadSound_2(GPData(sound))

func ExportWave wave, fileName
	return ExportWave_2(GPData(wave), fileName)

func ExportWaveAsCode wave, fileName
	return ExportWaveAsCode_2(GPData(wave), fileName)

func PlaySound sound
	return PlaySound_2(GPData(Sound))

func PauseSound sound
	return PauseSound_2(GPData(sound))

func ResumeSound sound
	return ResumeSound_2(GPData(sound))

func StopSound sound
	return StopSound_2(GPData(sound))

func IsSoundPlaying sound
	return IsSoundPlaying_2(GPData(sound))

func SetSoundVolume sound, volume
	return SetSoundVolume_2(GPData(sound), volume)

func SetSoundPitch sound, pitch
	return SetSoundPitch_2(GPData(sound), pitch)

func WaveFormat wave, sampleRate, sampleSize, channels
	return WaveFormat_2(GPData(wave), sampleRate, sampleSize, channels)

func WaveCopy wave
	oWave = new Wave
	oWave.setData( WaveCopy_2(GPData(wave)) )
	return oWave

func WaveCrop wave, initSample, finalSample
	return WaveCrop_2(GPData(wave), initSample, finalSample)

func GetWaveData wave
	return GetWaveData_2(GPData(wave))

func DrawTextEx font,text,position,fontSize,spacing,tint
	return DrawTextEx_2(GPData(font),text,GPData(position),fontSize,spacing,tint)

func DrawCubeTexture texture,position,width,height,length,color
	return DrawCubeTexture_2(GPData(texture),GPData(position),width,height,length,GPData(color))

func SetWindowIcon image 
	return SetWindowIcon_2( GPData(image) )

func BeginTextureMode target
	return BeginTextureMode_2( GPData(target) )

func ClearBackground color
	return ClearBackground_2( GPData(color) )

func ColorToInt color
	return ColorToInt_2( GPData(color) )

func ColorNormalize color 
	oVector4 = new Vector4 
	oVector4.setData( ColorNormalize_2(GPData(color)) )
	return oVector4 

func ColorToHSV color 
	oVector4 = new Vector4 
	oVector4.setData( ColorToHSV_2(GPData(color)) )
	return oVector4 

func Fade color, alpha 
	oColor = new Color 
	oColor.setData( Fade_2( GPData(color), alpha )  )
	return oColor 

func GetGestureDragVector 
	oVector2 = new Vector2 
	oVector2.setData( GetGestureDragVector_2() )
	return oVector2 

func GetGesturePinchVector 
	oVector2 = new Vector2 
	oVector2.setData( GetGesturePinchVector_2() )
	return oVector2 

func DrawPixel posX, posY, color 
	return DrawPixel_2(posX, posY, GPData(color))

func DrawLine startPosX, startPosY, endPosX, endPosY, color
	return DrawLine_2(startPosX, startPosY, endPosX, endPosY, GPData(color))

func DrawCircle centerX, centerY, radius, color
	return DrawCircle_2(centerX, centerY, radius, GPData(color) )

func DrawCircleGradient centerX, centerY, radius, color1, color2
	return DrawCircleGradient_2( centerX, centerY, radius, GPData(color1), GPData(color2) )

func DrawCircleLines centerX, centerY, radius, color
	return DrawCircleLines_2( centerX, centerY, radius, GPData(color) )

func DrawRectangle posX, posY, width, height, color 
	return DrawRectangle_2( posX, posY, width, height, GPData(color) )

func DrawRectangleGradientV posX, posY, width, height, color1, color2
	return DrawRectangleGradientV_2( posX, posY, width, height, GPData(color1), GPData(color2) )

func DrawRectangleGradientH posX, posY, width, height, color1, color2
	return DrawRectangleGradientH_2( posX, posY, width, height, GPData(color1), GPData(color2) )

func DrawRectangleLines posX, posY, width, height, color 
	return DrawRectangleLines_2(posX, posY, width, height, GPData(color))

func ExportImage image, fileName 
	return ExportImage_2( GPData(image), fileName ) 

func ExportImageAsCode image, fileName
	return ExportImageAsCode_2( GPData(image), fileName )

func LoadRenderTexture width, height
	oRenderTexture2D = new RenderTexture2D 
	oRenderTexture2D.setData( LoadRenderTexture_2(width, height) )
	return oRenderTexture2D

func UnloadRenderTexture target 
	return UnloadRenderTexture_2(GPData(target))

func GetImageDataNormalized image 
	oVector4 = new Vector4 
	oVector4.setData( GetImageDataNormalized_2( GPData(image) ) )
	return oVector4

func GetTextureData texture
	oImage = new Image 
	oImage.setData( GetTextureData_2( GPData(texture) ) )
	return oImage

func GetScreenData
	oImage = new Image 
	oImage.setData( GetScreenData_2() )
	return oImage

func UpdateTexture texture, pixels 
	return UpdateTexture_2( GPData(texture), pixels )

func ImageCopy image
	oImage = new Image 
	oImage.setData( ImageCopy_2(GPData(image)) )
	return oImage

func ImageToPOT image, fillColor
	return ImageToPOT_2( GPData(image), GPData(fillColor) )

func ImageFormat image, newFormat 
	return ImageFormat_2( GPData(image), newFormat )

func ImageAlphaMask image, alphaMask
	return ImageAlphaMask_2( GPData(image), GPData(alphaMask) )

func ImageAlphaClear image, color, threshold
	return ImageAlphaClear_2( GPData(image), GPData(color), threshold )

func ImageAlphaCrop image, threshold
	return ImageAlphaCrop_2( GPData(image), threshold )

func ImageAlphaPremultiply image
	return ImageAlphaPremultiply_2( GPData(image) )

func ImageResizeNN image, newWidth, newHeight
	return ImageResizeNN_2( GPData(image), newWidth, newHeight )

func ImageResizeCanvas image, newWidth, newHeight, offsetX, offsetY, color
	return ImageResizeCanvas_2( GPData(image), newWidth, newHeight, offsetX, offsetY, GPData(color) )

func ImageMipmaps image
	return ImageMipmaps_2( GPData(image) )

func ImageDither image, rBpp, gBpp, bBpp, aBpp
	return ImageDither_2( GPData(image), rBpp, gBpp, bBpp, aBpp )

func ImageExtractPalette image, maxPaletteSize, extractCount
	oColor = new Color 
	oColor.setData(ImageExtractPalette_2( GPData(image), maxPaletteSize, extractCount) )
 	return oColor

func ImageText text, fontSize, color
	oImage = new Image 
	oImage.setData(ImageText_2( text, fontSize, GPData(color) ) )
	return oImage

func ImageTextEx font, text, fontSize, spacing, tint
	oImage = new Image 
	oImage.setData(ImageTextEx_2( GPData(font), text, fontSize, spacing, GPData(tint) ) )
	return oImage

func GenImageColor width,  height, color
	oImage = new Image 
	oImage.setData(GenImageColor_2( width,  height, GPData(color) ) )
	return oImage

func GenImageGradientV width, height, top, bottom
	oImage = new Image 
	oImage.setData(GenImageGradientV_2( width, height, GPData(top), GPData(bottom)) )
	return oImage

func GenImageGradientH width, height, left, right
	oImage = new Image 
	oImage.setData(GenImageGradientH_2( width, height, GPData(left), GPData(right) ) )
	return oImage

func GenImageGradientRadial width, height, density, inner, outer
	oImage = new Image 
	oImage.setData(GenImageGradientRadial_2( width, height, density, GPData(inner), GPData(outer) ) )
	return oImage

func GenImageChecked width, height, checksX, checksY, col1, col2
	oImage = new Image 
	oImage.setData(GenImageChecked_2( width, height, checksX, checksY, GPData(col1), GPData(col2) ) )
	return oImage

func GenImageWhiteNoise width, height, factor
	oImage = new Image 
	oImage.setData(GenImageWhiteNoise_2(width, height, factor))
	return oImage

func GenImagePerlinNoise width, height, offsetX, offsetY, scale
	oImage = new Image 
	oImage.setData(GenImagePerlinNoise_2( width, height, offsetX, offsetY, scale) )
	return oImage

func GenImageCellular width, height, tileSize
	oImage = new Image 
	oImage.setData(GenImageCellular_2( width, height, tileSize) )
	return oImage

func GenTextureMipmaps texture
	return GenTextureMipmaps_2( GPData(texture) )

func SetTextureFilter texture, filterMode
	return SetTextureFilter_2( GPData(texture), filterMode )

func SetTextureWrap texture, wrapMode
	return SetTextureWrap_2( GPData(texture), wrapMode )

func DrawTextureV texture, position, tint
	return DrawTextureV_2( GPData(texture), GPData(position), GPData(tint) )

func GetFontDefault
	oFont = new Font 
	oFont.setData(GetFontDefault_2())
	return oFont

func LoadFontEx fileName, fontSize, fontChars, charsCount
	oFont = new Font 
	oFont.setData(LoadFontEx_2( fileName, fontSize, fontChars, charsCount ) )
	return oFont

func LoadFontFromImage image, key, firstChar
	oFont = new Font 
	oFont.setData(LoadFontFromImage_2( GPData(image), GPData(key), firstChar) )
	return oFont

func LoadFontData fileName, fontSize, fontChars, charsCount, type
	oCharInfo = new CharInfo
	oCharInfo.setData(LoadFontData_2( fileName, fontSize, fontChars, charsCount, type) )
	return oCharInfo

func GenImageFontAtlas chars, charsCount, fontSize, padding, packMethod
	oImage = new Image 
	oImage.setData(GenImageFontAtlas_2( GPData(chars), charsCount, fontSize, padding, packMethod ) )
	return oImage 

func MeasureTextEx font, text, fontSize, spacing
	oVector2 = new Vector2 
	oVector2.setData(MeasureTextEx_2( GPData(font), text, fontSize, spacing ) )
	return oVector2 

func GetGlyphIndex font, character 
	return GetGlyphIndex_2( GPData(font), character )

func LoadModel fileName
	oModel = new Model 
	oModel.setData(LoadModel_2( fileName ) )
	return oModel 

func LoadModelFromMesh mesh
	oModel = new Model 
	oModel.setData(LoadModelFromMesh_2( GPData(mesh) ) )
	return oModel 

func UnloadModel model
	return UnloadModel_2( GPData(model) )

func LoadMeshes fileName, meshCount
	oMesh = new Mesh 
	oMesh.setData(LoadMeshes_2( fileName, meshCount ) )
	return oMesh 

func ExportMesh mesh, fileName
	return ExportMesh_2( GPData(mesh), fileName )

func UnloadMesh mesh
	return UnloadMesh_2( GPData(mesh) )

func LoadMaterials fileName, materialCount
	oMaterial = new Material 
	oMaterial.setData(LoadMaterials_2( fileName, materialCount ) )
	return oMaterial

func LoadMaterialDefault
	oMaterial = new Material 
	oMaterial.setData(LoadMaterialDefault_2())
	return oMaterial

func UnloadMaterial material
	return UnloadMaterial_2( GPData(material) )

func SetMaterialTexture material, mapType, texture
	return SetMaterialTexture_2( GPData(material), mapType, GPData(texture) )

func SetModelMeshMaterial model, meshId, materialId
	return SetModelMeshMaterial_2( GPData(model), meshId, materialId )

func LoadModelAnimations fileName, animsCount
	oModelAnimation = new ModelAnimation
	oModelAnimation.setData(LoadModelAnimations_2( fileName, animsCount ) )
	return oModelAnimation

func UpdateModelAnimation model, anim, frame
	return UpdateModelAnimation_2( GPData(model), GPData(anim), frame )

func UnloadModelAnimation anim
	return UnloadModelAnimation_2( GPData(anim) )

func IsModelAnimationValid model, anim
	return IsModelAnimationValid_2( GPData(model), GPData(anim) )

func GenMeshPoly sides, radius
	oMesh = new Mesh 
	oMesh.setData(GenMeshPoly_2( sides, radius ) )
	return oMesh

func GenMeshPlane width, length, resX, resZ
	oMesh = new Mesh 
	oMesh.setData(GenMeshPlane_2( width, length, resX, resZ ) )
	return oMesh

func GenMeshCube width, height, length
	oMesh = new Mesh 
	oMesh.setData(GenMeshCube_2( width, height, length ) ) 
	return oMesh

func GenMeshSphere radius, rings, slices
	oMesh = new Mesh 
	oMesh.setData(GenMeshSphere_2( radius, rings, slices ) )
	return oMesh

func GenMeshHemiSphere radius, rings, slices
	oMesh = new Mesh 
	oMesh.setData(GenMeshHemiSphere_2( radius, rings, slices ) )
	return oMesh

func GenMeshCylinder radius, height, slices
	oMesh = new Mesh 
	oMesh.setData(GenMeshCylinder_2( radius, height, slices ) )
	return oMesh

func GenMeshTorus radius, size, radSeg, sides
	oMesh = new Mesh 
	oMesh.setData(GenMeshTorus_2( radius, size, radSeg, sides ) )
	return oMesh

func GenMeshKnot radius, size, radSeg, sides
	oMesh = new Mesh 
	oMesh.setData(GenMeshKnot_2( radius, size, radSeg, sides ) )
	return oMesh

func MeshBoundingBox mesh
	oBoundingBox = new BoundingBox
	oBoundingBox.setData(MeshBoundingBox_2( GPData(mesh) ))
	return oBoundingBox

func MeshTangents mesh
	return MeshTangents_2( GPData(mesh) )

func MeshBinormals mesh
	return MeshBinormals_2( GPData(mesh) )

func DrawBoundingBox box, color
	return DrawBoundingBox_2( GPData(box), GPData(color) )

func CheckCollisionBoxes box1, box2
	return CheckCollisionBoxes_2( GPData(box1), GPData(box2) )

func GetCollisionRayModel ray, model
	oRayHitInfo = new RayHitInfo
	oRayHitInfo.setData(GetCollisionRayModel_2( GPData(ray), GPData(model) ) )
	return oRayHitInfo

func GetCollisionRayGround ray, groundHeight
	oRayHitInfo = new RayHitInfo
	oRayHitInfo.setData(GetCollisionRayGround_2( GPData(ray), groundHeight ) )
	return oRayHitInfo

func LoadShader vsFileName, fsFileName
	oShader = new Shader 
	oShader.setData(LoadShader_2( vsFileName, fsFileName ))
	return oShader 

func LoadShaderCode vsCode, fsCode
	oShader = new Shader 
	oShader.setData(LoadShaderCode_2( vsCode, fsCode ))
	return oShader 

func UnloadShader shader
	return UnloadShader_2( GPData(shader) )

func GetShaderDefault
	oShader = new Shader 
	oShader.setData(GetShaderDefault_2())
	return oShader 

func GetTextureDefault
	oTexture2D = new Texture2D
	oTexture2D.setData(GetTextureDefault_2())
	return oTexture2D

func GetShaderLocation shader, uniformName
	return GetShaderLocation_2( GPData(shader), uniformName )

func SetShaderValue shader, uniformLoc, value, uniformType
	return SetShaderValue_2( GPData(shader), uniformLoc, value, uniformType )

func SetShaderValueV shader, uniformLoc, value, uniformType, count
	return SetShaderValueV_2( GPData(shader), uniformLoc, value, uniformType, count )

func SetShaderValueMatrix shader, uniformLoc, mat
	return SetShaderValueMatrix_2( GPData(shader), uniformLoc, GPData(mat) )

func SetShaderValueTexture shader, uniformLoc, texture
	return SetShaderValueTexture_2( GPData(shader), uniformLoc, GPData(texture) )

func SetMatrixProjection proj
	return SetMatrixProjection_2( GPData(proj) )

func SetMatrixModelview view
	return SetMatrixModelview_2( GPData(view) )

func GetMatrixModelview
	oMatrix = new Matrix
	oMatrix.setData(GetMatrixModelview_2())
	return oMatrix

func GenTextureCubemap shader, skyHDR, size
	oTexture2D = new Texture2D
	oTexture2D.setData(GenTextureCubemap_2( GPdata(shader), GPData(skyHDR), size ))
	return oTexture2D

func GenTextureIrradiance shader, cubemap, size
	oTexture2D = new Texture2D
	oTexture2D.setData(GenTextureIrradiance_2( GPData(shader), GPData(cubemap), size ))
	return oTexture2D

func GenTexturePrefilter shader, cubemap, size
	oTexture2D = new Texture2D
	oTexture2D.setData(GenTexturePrefilter_2( GPData(shader), GPData(cubemap), size ) )
	return oTexture2D

func GenTextureBRDF shader, size
	oTexture2D = new Texture2D
	oTexture2D.setData(GenTextureBRDF_2( GPData(shader), size ) )
	return oTexture2D

func BeginShaderMode shader
	return BeginShaderMode_2( GPData(shader) )

func SetVrConfiguration info, distortion
	return SetVrConfiguration_2( GPData(info), GPData(distortion) )

func LoadMusicStream fileName
	oMusic = new Music
	oMusic.setData(LoadMusicStream_2( fileName ))
	return oMusic

func UnloadMusicStream music
	return UnloadMusicStream_2( GPData(music) )

func PlayMusicStream music
	return PlayMusicStream_2( GPData(music) )

func UpdateMusicStream music
	return UpdateMusicStream_2( GPData(music) )

func StopMusicStream music
	return StopMusicStream_2( GPData(music) )

func PauseMusicStream music
	return PauseMusicStream_2( GPData(music) )

func ResumeMusicStream music
	return ResumeMusicStream_2( GPData(music) )

func IsMusicPlaying music
	return IsMusicPlaying_2( GPData(music) )

func SetMusicVolume music, volume
	return SetMusicVolume_2( GPData(music), volume )

func SetMusicPitch music, pitch
	return SetMusicPitch_2( GPData(music), pitch )

func SetMusicLoopCount music, count
	return SetMusicLoopCount_2( GPData(music), count )

func GetMusicTimeLength music
	return GetMusicTimeLength_2( GPData(music) )

func GetMusicTimePlayed music 
	return GetMusicTimePlayed_2( GPData(music) )

func InitAudioStream sampleRate, sampleSize, channels
	oAudioStream = new AudioStream
	oAudioStream.setData(InitAudioStream_2( sampleRate, sampleSize, channels ))
	return oAudioStream

func UpdateAudioStream stream, data, samplesCount
	return UpdateAudioStream_2( GPData(stream), data, samplesCount )

func CloseAudioStream stream
	return CloseAudioStream_2( GPData(stream) )

func IsAudioBufferProcessed stream
	return IsAudioBufferProcessed_2( GPData(stream) )

func PlayAudioStream stream
	return PlayAudioStream_2( GPData(stream) )

func PauseAudioStream stream
	return PauseAudioStream_2( GPData(stream) )

func ResumeAudioStream stream
	return ResumeAudioStream_2( GPData(stream) )

func IsAudioStreamPlaying stream
	return IsAudioStreamPlaying_2( GPData(stream) )

func StopAudioStream stream
	return StopAudioStream_2( GPData(stream) )

func SetAudioStreamVolume stream, volume
	return SetAudioStreamVolume_2( GPData(stream), volume )

func SetAudioStreamPitch stream, pitch
	return SetAudioStreamPitch_2( GPData(stream), pitch )

func getimagepixelr p1, y, x, width 
	return getimagepixelr_2(GPData(p1), y, x, width)

func Vector2Zero 
	oVector2 = new Vector2
	oVector2.setData( Vector2Zero_2() )
	return oVector2


func Vector2One 
	oVector2 = new Vector2
	oVector2.setData( Vector2One_2() )
	return oVector2


func Vector2Add p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Add_2(GPData(p1),GPData(p2)) )
	return oVector2


func Vector2AddValue p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2AddValue_2(GPData(p1),p2) )
	return oVector2


func Vector2Subtract p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Subtract_2(GPData(p1),GPData(p2)) )
	return oVector2


func Vector2SubtractValue p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2SubtractValue_2(GPData(p1),p2) )
	return oVector2


func Vector2Length p1
	return Vector2Length_2(GPData(p1))



func Vector2LengthSqr p1
	return Vector2LengthSqr_2(GPData(p1))



func Vector2DotProduct p1,p2
	return Vector2DotProduct_2(GPData(p1),GPData(p2))



func Vector2Distance p1,p2
	return Vector2Distance_2(GPData(p1),GPData(p2))



func Vector2Angle p1,p2
	return Vector2Angle_2(GPData(p1),GPData(p2))



func Vector2Scale p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Scale_2(GPData(p1),p2) )
	return oVector2


func Vector2Multiply p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Multiply_2(GPData(p1),GPData(p2)) )
	return oVector2


func Vector2Negate p1
	oVector2 = new Vector2
	oVector2.setData( Vector2Negate_2(GPData(p1)) )
	return oVector2


func Vector2Divide p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Divide_2(GPData(p1),GPData(p2)) )
	return oVector2


func Vector2Normalize p1
	oVector2 = new Vector2
	oVector2.setData( Vector2Normalize_2(GPData(p1)) )
	return oVector2


func Vector2Lerp p1,p2,p3
	oVector2 = new Vector2
	oVector2.setData( Vector2Lerp_2(GPData(p1),GPData(p2),p3) )
	return oVector2


func Vector2Rotate p1,p2
	oVector2 = new Vector2
	oVector2.setData( Vector2Rotate_2(GPData(p1),p2) )
	return oVector2


func Vector2MoveTowards p1,p2,p3
	oVector2 = new Vector2
	oVector2.setData( Vector2MoveTowards_2(GPData(p1),GPData(p2),p3) )
	return oVector2


func Vector3Zero 
	oVector3 = new Vector3
	oVector3.setData( Vector3Zero_2() )
	return oVector3


func Vector3One 
	oVector3 = new Vector3
	oVector3.setData( Vector3One_2() )
	return oVector3


func Vector3Add p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Add_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3AddValue p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3AddValue_2(GPData(p1),p2) )
	return oVector3


func Vector3Subtract p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Subtract_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3SubtractValue p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3SubtractValue_2(GPData(p1),p2) )
	return oVector3


func Vector3Scale p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Scale_2(GPData(p1),p2) )
	return oVector3


func Vector3Multiply p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Multiply_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3CrossProduct p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3CrossProduct_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Perpendicular p1
	oVector3 = new Vector3
	oVector3.setData( Vector3Perpendicular_2(GPData(p1)) )
	return oVector3


func Vector3Length p1
	return Vector3Length_2(p1)



func Vector3LengthSqr p1
	return Vector3LengthSqr_2(p1)



func Vector3DotProduct p1,p2
	return Vector3DotProduct_2(GPData(p1),GPData(p2))



func Vector3Distance p1,p2
	return Vector3Distance_2(GPData(p1),GPData(p2))



func Vector3Negate p1
	oVector3 = new Vector3
	oVector3.setData( Vector3Negate_2(GPData(p1)) )
	return oVector3


func Vector3Divide p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Divide_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Normalize p1
	oVector3 = new Vector3
	oVector3.setData( Vector3Normalize_2(GPData(p1)) )
	return oVector3


func Vector3OrthoNormalize p1,p2
	return Vector3OrthoNormalize_2(p1,p2)



func Vector3Transform p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Transform_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3RotateByQuaternion p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3RotateByQuaternion_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Lerp p1,p2,p3
	oVector3 = new Vector3
	oVector3.setData( Vector3Lerp_2(GPData(p1),GPData(p2),p3) )
	return oVector3


func Vector3Reflect p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Reflect_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Min p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Min_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Max p1,p2
	oVector3 = new Vector3
	oVector3.setData( Vector3Max_2(GPData(p1),GPData(p2)) )
	return oVector3


func Vector3Barycenter p1,p2,p3,p4
	oVector3 = new Vector3
	oVector3.setData( Vector3Barycenter_2(GPData(p1),GPData(p2),GPData(p3),GPData(p4)) )
	return oVector3


func Vector3ToFloatV p1
	return Vector3ToFloatV_2(GPData(p1))



func MatrixDeterminant p1
	return MatrixDeterminant_2(GPData(p1))



func MatrixTrace p1
	return MatrixTrace_2(GPData(p1))



func MatrixTranspose p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixTranspose_2(GPData(p1)) )
	return oMatrix


func MatrixInvert p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixInvert_2(GPData(p1)) )
	return oMatrix


func MatrixNormalize p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixNormalize_2(GPData(p1)) )
	return oMatrix


func MatrixIdentity 
	oMatrix = new Matrix
	oMatrix.setData( MatrixIdentity_2() )
	return oMatrix


func MatrixAdd p1,p2
	oMatrix = new Matrix
	oMatrix.setData( MatrixAdd_2(GPData(p1),GPData(p2)) )
	return oMatrix


func MatrixSubtract p1,p2
	oMatrix = new Matrix
	oMatrix.setData( MatrixSubtract_2(GPData(p1),GPData(p2)) )
	return oMatrix


func MatrixTranslate p1,p2,p3
	oMatrix = new Matrix
	oMatrix.setData( MatrixTranslate_2(p1,p2,p3) )
	return oMatrix


func MatrixRotate p1,p2
	oMatrix = new Matrix
	oMatrix.setData( MatrixRotate_2(GPData(p1),p2) )
	return oMatrix


func MatrixRotateXYZ p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixRotateXYZ_2(GPData(p1)) )
	return oMatrix


func MatrixRotateX p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixRotateX_2(p1) )
	return oMatrix


func MatrixRotateY p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixRotateY_2(p1) )
	return oMatrix


func MatrixRotateZ p1
	oMatrix = new Matrix
	oMatrix.setData( MatrixRotateZ_2(p1) )
	return oMatrix


func MatrixScale p1,p2,p3
	oMatrix = new Matrix
	oMatrix.setData( MatrixScale_2(p1,p2,p3) )
	return oMatrix


func MatrixMultiply p1,p2
	oMatrix = new Matrix
	oMatrix.setData( MatrixMultiply_2(GPData(p1),GPData(p2)) )
	return oMatrix


func MatrixFrustum p1,p2,p3,p4,p5,p6
	oMatrix = new Matrix
	oMatrix.setData( MatrixFrustum_2(p1,p2,p3,p4,p5,p6) )
	return oMatrix


func MatrixPerspective p1,p2,p3,p4
	oMatrix = new Matrix
	oMatrix.setData( MatrixPerspective_2(p1,p2,p3,p4) )
	return oMatrix


func MatrixOrtho p1,p2,p3,p4,p5,p6
	oMatrix = new Matrix
	oMatrix.setData( MatrixOrtho_2(p1,p2,p3,p4,p5,p6) )
	return oMatrix


func MatrixLookAt p1,p2,p3
	oMatrix = new Matrix
	oMatrix.setData( MatrixLookAt_2(GPData(p1),GPData(p2),GPData(p3)) )
	return oMatrix


func MatrixToFloatV p1
	return MatrixToFloatV_2(GPData(p1))



func QuaternionAdd p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionAdd_2(GPData(p1),GPData(p2)) )
	return oQuaternion


func QuaternionAddValue p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionAddValue_2(GPData(p1),p2) )
	return oQuaternion


func QuaternionSubtract p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionSubtract_2(GPData(p1),GPData(p2)) )
	return oQuaternion


func QuaternionSubtractValue p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionSubtractValue_2(GPData(p1),p2) )
	return oQuaternion


func QuaternionIdentity 
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionIdentity_2() )
	return oQuaternion


func QuaternionLength p1
	return QuaternionLength_2(GPData(p1))



func QuaternionNormalize p1
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionNormalize_2(GPData(p1)) )
	return oQuaternion


func QuaternionInvert p1
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionInvert_2(GPData(p1)) )
	return oQuaternion


func QuaternionMultiply p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionMultiply_2(GPData(p1),GPData(p2)) )
	return oQuaternion


func QuaternionScale p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionScale_2(GPData(p1),p2) )
	return oQuaternion


func QuaternionDivide p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionDivide_2(GPData(p1),GPData(p2)) )
	return oQuaternion


func QuaternionLerp p1,p2,p3
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionLerp_2(GPData(p1),GPData(p2),p3) )
	return oQuaternion


func QuaternionNlerp p1,p2,p3
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionNlerp_2(GPData(p1),GPData(p2),p3) )
	return oQuaternion


func QuaternionSlerp p1,p2,p3
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionSlerp_2(GPData(p1),GPData(p2),p3) )
	return oQuaternion


func QuaternionFromVector3ToVector3 p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionFromVector3ToVector3_2(GPData(p1),GPData(p2)) )
	return oQuaternion


func QuaternionFromMatrix p1
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionFromMatrix_2(GPData(p1)) )
	return oQuaternion


func QuaternionToMatrix p1
	oMatrix = new Matrix
	oMatrix.setData( QuaternionToMatrix_2(GPData(p1)) )
	return oMatrix


func QuaternionFromAxisAngle p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionFromAxisAngle_2(GPData(p1),p2) )
	return oQuaternion


func QuaternionToAxisAngle p1,p2,p3
	return QuaternionToAxisAngle_2(GPData(p1),p2,p3)



func QuaternionFromEuler p1,p2,p3
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionFromEuler_2(p1,p2,p3) )
	return oQuaternion


func QuaternionToEuler p1
	oVector3 = new Vector3
	oVector3.setData( QuaternionToEuler_2(GPData(p1)) )
	return oVector3


func QuaternionTransform p1,p2
	oQuaternion = new Quaternion
	oQuaternion.setData( QuaternionTransform_2(GPData(p1),GPData(p2)) )
	return oQuaternion


