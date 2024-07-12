func SetShaderInt shader, Location, Value

	valueInt = int2bytes(value)
	SetShaderValue(shader, Location, varptr(:valueInt,:void), UNIFORM_INT)

func SetShaderFloat shader, Location, Value

	valueFloat = float2bytes(value)
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_FLOAT)

func SetShaderVec2 shader, Location, Value

	valueFloat = float2bytes(Value[1]) + float2bytes(Value[2])
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_VEC2)

func SetShaderVec3 shader, Location, Value

	valueFloat = float2bytes(Value[1]) + float2bytes(Value[2]) + float2bytes(Value[3])
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_VEC3)

func SetShaderVec4 shader, Location, Value

	valueFloat = float2bytes(Value[1]) + float2bytes(Value[2]) + 
		     float2bytes(Value[3]) + float2bytes(Value[4])
	SetShaderValue(shader, Location, varptr(:valueFloat,:void), UNIFORM_VEC4)

func SetShaderIVec2 shader, Location, Value

	valueInt = int2bytes(Value[1]) + int2bytes(Value[2])
	SetShaderValue(shader, Location, varptr(:valueInt,:void), UNIFORM_IVEC2)

func SetShaderIVec3 shader, Location, Value

	valueInt = int2bytes(Value[1]) + int2bytes(Value[2]) + int2bytes(Value[3])
	SetShaderValue(shader, Location, varptr(:valueInt,:void), UNIFORM_IVEC3)

func SetShaderIVec4 shader, Location, Value

	valueInt = int2bytes(Value[1]) + int2bytes(Value[2]) + 
		     int2bytes(Value[3]) + int2bytes(Value[4])
	SetShaderValue(shader, Location, varptr(:valueInt,:void), UNIFORM_IVEC4)
