func SetShaderFloat shader, Location, Value

	valueFloat = float2bytes(value)
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_FLOAT)

func SetShaderVec2 shader, Location, Value

	valueFloat = float2bytes(Value[1]) + float2bytes(Value[2])
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_VEC2)