//============================================================================================================
//
//
//                  Copyright (c) 2023, Qualcomm Innovation Center, Inc. All rights reserved.
//                              SPDX-License-Identifier: BSD-3-Clause
//
//============================================================================================================
#pragma once

#include "ShaderParameterMacros.h"
#include "Runtime/Launch/Resources/Version.h"

#define SGSR_CPU_CONFIG
#include "../Shaders/Private/sgsr.ush"

//
// SHADER PASS PARAMETERS
//
enum class ESGSR_OutputDevice
{
	sRGB = 0,
	Linear,
	PQ,
	scRGB,
	MAX
};

enum class ESGSR_OutputDeviceMaxNits
{
	ESGSR_1000Nits,
	ESGSR_2000Nits,
	MAX
};

//
// SHADER PASS PARAMETERS
//
#if ENGINE_MAJOR_VERSION == 5

BEGIN_SHADER_PARAMETER_STRUCT(FSGSRPassParameters, )
	SHADER_PARAMETER(FVector4f, Const0)
	SHADER_PARAMETER(FVector4f, Const1)
	SHADER_PARAMETER_SAMPLER(SamplerState, samLinearClamp)
	SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
END_SHADER_PARAMETER_STRUCT()

#else // ENGINE_MAJOR_VERSION == 4

BEGIN_SHADER_PARAMETER_STRUCT(FSGSRPassParameters, )
SHADER_PARAMETER(FVector4, Const0)
SHADER_PARAMETER(FVector4, Const1)
SHADER_PARAMETER_SAMPLER(SamplerState, samLinearClamp)
SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
END_SHADER_PARAMETER_STRUCT()

#endif

BEGIN_SHADER_PARAMETER_STRUCT(FTextureCopyPassParameters, )
SHADER_PARAMETER_RDG_TEXTURE(Texture2D, InputTexture)
END_SHADER_PARAMETER_STRUCT()