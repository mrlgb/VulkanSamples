/*
 * XGL
 *
 * Copyright (C) 2014 LunarG, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "icd.h"
#include "cmd.h"
#include "dev.h"
#include "dset.h"
#include "event.h"
#include "fence.h"
#include "format.h"
#include "img.h"
#include "gpu.h"
#include "mem.h"
#include "obj.h"
#include "query.h"
#include "queue.h"
#include "sampler.h"
#include "state.h"
#include "view.h"
#include "dispatch.h"

static XGL_RESULT XGLAPI intelCreateShader(
    XGL_DEVICE                                  device,
    const XGL_SHADER_CREATE_INFO*               pCreateInfo,
    XGL_SHADER*                                 pShader)
{
    return XGL_ERROR_UNAVAILABLE;
}

static XGL_RESULT XGLAPI intelCreateGraphicsPipeline(
    XGL_DEVICE                                  device,
    const XGL_GRAPHICS_PIPELINE_CREATE_INFO*    pCreateInfo,
    XGL_PIPELINE*                               pPipeline)
{
    return XGL_ERROR_UNAVAILABLE;
}

static XGL_RESULT XGLAPI intelCreateComputePipeline(
    XGL_DEVICE                                  device,
    const XGL_COMPUTE_PIPELINE_CREATE_INFO*     pCreateInfo,
    XGL_PIPELINE*                               pPipeline)
{
    return XGL_ERROR_UNAVAILABLE;
}

static XGL_RESULT XGLAPI intelStorePipeline(
    XGL_PIPELINE                                pipeline,
    XGL_SIZE*                                   pDataSize,
    XGL_VOID*                                   pData)
{
    return XGL_ERROR_UNAVAILABLE;
}

static XGL_RESULT XGLAPI intelLoadPipeline(
    XGL_DEVICE                                  device,
    XGL_SIZE                                    dataSize,
    const XGL_VOID*                             pData,
    XGL_PIPELINE*                               pPipeline)
{
    return XGL_ERROR_UNAVAILABLE;
}

static XGL_RESULT XGLAPI intelCreatePipelineDelta(
    XGL_DEVICE                                  device,
    XGL_PIPELINE                                p1,
    XGL_PIPELINE                                p2,
    XGL_PIPELINE_DELTA*                         delta)
{
    return XGL_ERROR_UNAVAILABLE;
}

static const struct icd_dispatch_table intel_normal_dispatch_table = {
    .InitAndEnumerateGpus = xglInitAndEnumerateGpus,
    .GetGpuInfo = intelGetGpuInfo,
    .CreateDevice = intelCreateDevice,
    .DestroyDevice = intelDestroyDevice,
    .GetExtensionSupport = intelGetExtensionSupport,
    .GetDeviceQueue = intelGetDeviceQueue,
    .QueueSubmit = intelQueueSubmit,
    .QueueSetGlobalMemReferences = intelQueueSetGlobalMemReferences,
    .QueueWaitIdle = intelQueueWaitIdle,
    .DeviceWaitIdle = intelDeviceWaitIdle,
    .GetMemoryHeapCount = intelGetMemoryHeapCount,
    .GetMemoryHeapInfo = intelGetMemoryHeapInfo,
    .AllocMemory = intelAllocMemory,
    .FreeMemory = intelFreeMemory,
    .SetMemoryPriority = intelSetMemoryPriority,
    .MapMemory = intelMapMemory,
    .UnmapMemory = intelUnmapMemory,
    .PinSystemMemory = intelPinSystemMemory,
    .RemapVirtualMemoryPages = intelRemapVirtualMemoryPages,
    .GetMultiGpuCompatibility = intelGetMultiGpuCompatibility,
    .OpenSharedMemory = intelOpenSharedMemory,
    .OpenSharedQueueSemaphore = intelOpenSharedQueueSemaphore,
    .OpenPeerMemory = intelOpenPeerMemory,
    .OpenPeerImage = intelOpenPeerImage,
    .DestroyObject = intelDestroyObject,
    .GetObjectInfo = intelGetObjectInfo,
    .BindObjectMemory = intelBindObjectMemory,
    .CreateFence = intelCreateFence,
    .GetFenceStatus = intelGetFenceStatus,
    .WaitForFences = intelWaitForFences,
    .CreateQueueSemaphore = intelCreateQueueSemaphore,
    .SignalQueueSemaphore = intelSignalQueueSemaphore,
    .WaitQueueSemaphore = intelWaitQueueSemaphore,
    .CreateEvent = intelCreateEvent,
    .GetEventStatus = intelGetEventStatus,
    .SetEvent = intelSetEvent,
    .ResetEvent = intelResetEvent,
    .CreateQueryPool = intelCreateQueryPool,
    .GetQueryPoolResults = intelGetQueryPoolResults,
    .GetFormatInfo = intelGetFormatInfo,
    .CreateImage = intelCreateImage,
    .GetImageSubresourceInfo = intelGetImageSubresourceInfo,
    .CreateImageView = intelCreateImageView,
    .CreateColorAttachmentView = intelCreateColorAttachmentView,
    .CreateDepthStencilView = intelCreateDepthStencilView,
    .CreateShader = intelCreateShader,
    .CreateGraphicsPipeline = intelCreateGraphicsPipeline,
    .CreateComputePipeline = intelCreateComputePipeline,
    .StorePipeline = intelStorePipeline,
    .LoadPipeline = intelLoadPipeline,
    .CreatePipelineDelta = intelCreatePipelineDelta,
    .CreateSampler = intelCreateSampler,
    .CreateDescriptorSet = intelCreateDescriptorSet,
    .BeginDescriptorSetUpdate = intelBeginDescriptorSetUpdate,
    .EndDescriptorSetUpdate = intelEndDescriptorSetUpdate,
    .AttachSamplerDescriptors = intelAttachSamplerDescriptors,
    .AttachImageViewDescriptors = intelAttachImageViewDescriptors,
    .AttachMemoryViewDescriptors = intelAttachMemoryViewDescriptors,
    .AttachNestedDescriptors = intelAttachNestedDescriptors,
    .ClearDescriptorSetSlots = intelClearDescriptorSetSlots,
    .CreateViewportState = intelCreateViewportState,
    .CreateRasterState = intelCreateRasterState,
    .CreateMsaaState = intelCreateMsaaState,
    .CreateColorBlendState = intelCreateColorBlendState,
    .CreateDepthStencilState = intelCreateDepthStencilState,
    .CreateCommandBuffer = intelCreateCommandBuffer,
    .BeginCommandBuffer = intelBeginCommandBuffer,
    .EndCommandBuffer = intelEndCommandBuffer,
    .ResetCommandBuffer = intelResetCommandBuffer,
    .CmdBindPipeline = intelCmdBindPipeline,
    .CmdBindPipelineDelta = intelCmdBindPipelineDelta,
    .CmdBindStateObject = intelCmdBindStateObject,
    .CmdBindDescriptorSet = intelCmdBindDescriptorSet,
    .CmdBindDynamicMemoryView = intelCmdBindDynamicMemoryView,
    .CmdBindIndexData = intelCmdBindIndexData,
    .CmdBindAttachments = intelCmdBindAttachments,
    .CmdPrepareMemoryRegions = intelCmdPrepareMemoryRegions,
    .CmdPrepareImages = intelCmdPrepareImages,
    .CmdDraw = intelCmdDraw,
    .CmdDrawIndexed = intelCmdDrawIndexed,
    .CmdDrawIndirect = intelCmdDrawIndirect,
    .CmdDrawIndexedIndirect = intelCmdDrawIndexedIndirect,
    .CmdDispatch = intelCmdDispatch,
    .CmdDispatchIndirect = intelCmdDispatchIndirect,
    .CmdCopyMemory = intelCmdCopyMemory,
    .CmdCopyImage = intelCmdCopyImage,
    .CmdCopyMemoryToImage = intelCmdCopyMemoryToImage,
    .CmdCopyImageToMemory = intelCmdCopyImageToMemory,
    .CmdCloneImageData = intelCmdCloneImageData,
    .CmdUpdateMemory = intelCmdUpdateMemory,
    .CmdFillMemory = intelCmdFillMemory,
    .CmdClearColorImage = intelCmdClearColorImage,
    .CmdClearColorImageRaw = intelCmdClearColorImageRaw,
    .CmdClearDepthStencil = intelCmdClearDepthStencil,
    .CmdResolveImage = intelCmdResolveImage,
    .CmdSetEvent = intelCmdSetEvent,
    .CmdResetEvent = intelCmdResetEvent,
    .CmdMemoryAtomic = intelCmdMemoryAtomic,
    .CmdBeginQuery = intelCmdBeginQuery,
    .CmdEndQuery = intelCmdEndQuery,
    .CmdResetQueryPool = intelCmdResetQueryPool,
    .CmdWriteTimestamp = intelCmdWriteTimestamp,
    .CmdInitAtomicCounters = intelCmdInitAtomicCounters,
    .CmdLoadAtomicCounters = intelCmdLoadAtomicCounters,
    .CmdSaveAtomicCounters = intelCmdSaveAtomicCounters,
    .DbgSetValidationLevel = intelDbgSetValidationLevel,
    .DbgRegisterMsgCallback = xglDbgRegisterMsgCallback,
    .DbgUnregisterMsgCallback = xglDbgUnregisterMsgCallback,
    .DbgSetMessageFilter = intelDbgSetMessageFilter,
    .DbgSetObjectTag = intelDbgSetObjectTag,
    .DbgSetGlobalOption = xglDbgSetGlobalOption,
    .DbgSetDeviceOption = intelDbgSetDeviceOption,
    .CmdDbgMarkerBegin = intelCmdDbgMarkerBegin,
    .CmdDbgMarkerEnd = intelCmdDbgMarkerEnd,
};

static const struct icd_dispatch_table intel_debug_dispatch_table = {
    .InitAndEnumerateGpus = xglInitAndEnumerateGpus,
    .GetGpuInfo = intelGetGpuInfo,
    .CreateDevice = intelCreateDevice,
    .DestroyDevice = intelDestroyDevice,
    .GetExtensionSupport = intelGetExtensionSupport,
    .GetDeviceQueue = intelGetDeviceQueue,
    .QueueSubmit = intelQueueSubmit,
    .QueueSetGlobalMemReferences = intelQueueSetGlobalMemReferences,
    .QueueWaitIdle = intelQueueWaitIdle,
    .DeviceWaitIdle = intelDeviceWaitIdle,
    .GetMemoryHeapCount = intelGetMemoryHeapCount,
    .GetMemoryHeapInfo = intelGetMemoryHeapInfo,
    .AllocMemory = intelAllocMemory,
    .FreeMemory = intelFreeMemory,
    .SetMemoryPriority = intelSetMemoryPriority,
    .MapMemory = intelMapMemory,
    .UnmapMemory = intelUnmapMemory,
    .PinSystemMemory = intelPinSystemMemory,
    .RemapVirtualMemoryPages = intelRemapVirtualMemoryPages,
    .GetMultiGpuCompatibility = intelGetMultiGpuCompatibility,
    .OpenSharedMemory = intelOpenSharedMemory,
    .OpenSharedQueueSemaphore = intelOpenSharedQueueSemaphore,
    .OpenPeerMemory = intelOpenPeerMemory,
    .OpenPeerImage = intelOpenPeerImage,
    .DestroyObject = intelDestroyObject,
    .GetObjectInfo = intelGetObjectInfo,
    .BindObjectMemory = intelBindObjectMemory,
    .CreateFence = intelCreateFence,
    .GetFenceStatus = intelGetFenceStatus,
    .WaitForFences = intelWaitForFences,
    .CreateQueueSemaphore = intelCreateQueueSemaphore,
    .SignalQueueSemaphore = intelSignalQueueSemaphore,
    .WaitQueueSemaphore = intelWaitQueueSemaphore,
    .CreateEvent = intelCreateEvent,
    .GetEventStatus = intelGetEventStatus,
    .SetEvent = intelSetEvent,
    .ResetEvent = intelResetEvent,
    .CreateQueryPool = intelCreateQueryPool,
    .GetQueryPoolResults = intelGetQueryPoolResults,
    .GetFormatInfo = intelGetFormatInfo,
    .CreateImage = intelCreateImage,
    .GetImageSubresourceInfo = intelGetImageSubresourceInfo,
    .CreateImageView = intelCreateImageView,
    .CreateColorAttachmentView = intelCreateColorAttachmentView,
    .CreateDepthStencilView = intelCreateDepthStencilView,
    .CreateShader = intelCreateShader,
    .CreateGraphicsPipeline = intelCreateGraphicsPipeline,
    .CreateComputePipeline = intelCreateComputePipeline,
    .StorePipeline = intelStorePipeline,
    .LoadPipeline = intelLoadPipeline,
    .CreatePipelineDelta = intelCreatePipelineDelta,
    .CreateSampler = intelCreateSampler,
    .CreateDescriptorSet = intelCreateDescriptorSet,
    .BeginDescriptorSetUpdate = intelBeginDescriptorSetUpdate,
    .EndDescriptorSetUpdate = intelEndDescriptorSetUpdate,
    .AttachSamplerDescriptors = intelAttachSamplerDescriptors,
    .AttachImageViewDescriptors = intelAttachImageViewDescriptors,
    .AttachMemoryViewDescriptors = intelAttachMemoryViewDescriptors,
    .AttachNestedDescriptors = intelAttachNestedDescriptors,
    .ClearDescriptorSetSlots = intelClearDescriptorSetSlots,
    .CreateViewportState = intelCreateViewportState,
    .CreateRasterState = intelCreateRasterState,
    .CreateMsaaState = intelCreateMsaaState,
    .CreateColorBlendState = intelCreateColorBlendState,
    .CreateDepthStencilState = intelCreateDepthStencilState,
    .CreateCommandBuffer = intelCreateCommandBuffer,
    .BeginCommandBuffer = intelBeginCommandBuffer,
    .EndCommandBuffer = intelEndCommandBuffer,
    .ResetCommandBuffer = intelResetCommandBuffer,
    .CmdBindPipeline = intelCmdBindPipeline,
    .CmdBindPipelineDelta = intelCmdBindPipelineDelta,
    .CmdBindStateObject = intelCmdBindStateObject,
    .CmdBindDescriptorSet = intelCmdBindDescriptorSet,
    .CmdBindDynamicMemoryView = intelCmdBindDynamicMemoryView,
    .CmdBindIndexData = intelCmdBindIndexData,
    .CmdBindAttachments = intelCmdBindAttachments,
    .CmdPrepareMemoryRegions = intelCmdPrepareMemoryRegions,
    .CmdPrepareImages = intelCmdPrepareImages,
    .CmdDraw = intelCmdDraw,
    .CmdDrawIndexed = intelCmdDrawIndexed,
    .CmdDrawIndirect = intelCmdDrawIndirect,
    .CmdDrawIndexedIndirect = intelCmdDrawIndexedIndirect,
    .CmdDispatch = intelCmdDispatch,
    .CmdDispatchIndirect = intelCmdDispatchIndirect,
    .CmdCopyMemory = intelCmdCopyMemory,
    .CmdCopyImage = intelCmdCopyImage,
    .CmdCopyMemoryToImage = intelCmdCopyMemoryToImage,
    .CmdCopyImageToMemory = intelCmdCopyImageToMemory,
    .CmdCloneImageData = intelCmdCloneImageData,
    .CmdUpdateMemory = intelCmdUpdateMemory,
    .CmdFillMemory = intelCmdFillMemory,
    .CmdClearColorImage = intelCmdClearColorImage,
    .CmdClearColorImageRaw = intelCmdClearColorImageRaw,
    .CmdClearDepthStencil = intelCmdClearDepthStencil,
    .CmdResolveImage = intelCmdResolveImage,
    .CmdSetEvent = intelCmdSetEvent,
    .CmdResetEvent = intelCmdResetEvent,
    .CmdMemoryAtomic = intelCmdMemoryAtomic,
    .CmdBeginQuery = intelCmdBeginQuery,
    .CmdEndQuery = intelCmdEndQuery,
    .CmdResetQueryPool = intelCmdResetQueryPool,
    .CmdWriteTimestamp = intelCmdWriteTimestamp,
    .CmdInitAtomicCounters = intelCmdInitAtomicCounters,
    .CmdLoadAtomicCounters = intelCmdLoadAtomicCounters,
    .CmdSaveAtomicCounters = intelCmdSaveAtomicCounters,
    .DbgSetValidationLevel = intelDbgSetValidationLevel,
    .DbgRegisterMsgCallback = xglDbgRegisterMsgCallback,
    .DbgUnregisterMsgCallback = xglDbgUnregisterMsgCallback,
    .DbgSetMessageFilter = intelDbgSetMessageFilter,
    .DbgSetObjectTag = intelDbgSetObjectTag,
    .DbgSetGlobalOption = xglDbgSetGlobalOption,
    .DbgSetDeviceOption = intelDbgSetDeviceOption,
    .CmdDbgMarkerBegin = intelCmdDbgMarkerBegin,
    .CmdDbgMarkerEnd = intelCmdDbgMarkerEnd,
};

const struct icd_dispatch_table *intel_dispatch_get(bool debug)
{
    return (debug) ? &intel_debug_dispatch_table :
        &intel_normal_dispatch_table;
}
