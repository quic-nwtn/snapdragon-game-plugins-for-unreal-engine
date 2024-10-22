//============================================================================================================
//
//
//                  Copyright (c) 2024, Qualcomm Innovation Center, Inc. All rights reserved.
//                              SPDX-License-Identifier: BSD-3-Clause
//
//============================================================================================================

#pragma once

#include "CoreMinimal.h"
#include "SceneRendering.h"
#include "HAL/Platform.h"

class FGSRTU;

//////GSR state, deletion handled by RHI
struct FGSRState : public FRHIResource
{
	//FGSRState(uint32 const size)
	FGSRState()
	: FRHIResource(false)
	, LastUsedFrame(~0u)
	{
	}
	~FGSRState()
	{
	}

	uint32 AddRef() const
	{
		return FRHIResource::AddRef();
	}

	uint32 Release() const
	{
		return FRHIResource::Release();
	}

	uint32 GetRefCount() const
	{
		return FRHIResource::GetRefCount();
	}

	uint64 LastUsedFrame;
	uint32 ViewID;
};
typedef TRefCountPtr<FGSRState> GSRstateRef;


/////ICustomTemporalAAHistory for GSR
class FGSRTUHistory final : public ICustomTemporalAAHistory, public FRefCountBase
{
public:
	FGSRTUHistory(GSRstateRef state, FGSRTU* upscaler);
	virtual ~FGSRTUHistory();

//////originally in .cpp
	void Setstate(GSRstateRef state);

	inline GSRstateRef const& Getstate() const
	{
		return GSR;
	}

	uint32 AddRef() const final
	{
		return FRefCountBase::AddRef();
	}

	uint32 Release() const final
	{
		return FRefCountBase::Release();
	}

	uint32 GetRefCount() const final
	{
		return FRefCountBase::GetRefCount();
	}

private:
	GSRstateRef GSR;
	FGSRTU* upscaler;
};