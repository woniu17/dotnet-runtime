#pragma once
#include <atomic>
#include <cor.h>
#include <corprof.h>

#include "Logger.hpp"

namespace FeatLin { namespace Profiler {

    class ProfilerBase : public ICorProfilerCallback4 {

    private:
        std::atomic<int> _referenceCount;

    public:
        ProfilerBase()
            : _referenceCount(0)
        {
            LOG_INFO("ProfilerBase contructor");
        }

        ~ProfilerBase()
        {
            LOG_INFO("ProfilerBase destory");
        }

        // Unimplemented ICorProfilerCallback
        virtual HRESULT __stdcall AppDomainCreationStarted(AppDomainID appDomainId) override { return S_OK; }
        virtual HRESULT __stdcall AppDomainCreationFinished(AppDomainID appDomainId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall AppDomainShutdownStarted(AppDomainID appDomainId) override { return S_OK; }
        virtual HRESULT __stdcall AppDomainShutdownFinished(AppDomainID appDomainId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall AssemblyLoadStarted(AssemblyID assemblyId) override { return S_OK; }
        virtual HRESULT __stdcall AssemblyLoadFinished(AssemblyID assemblyId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall AssemblyUnloadStarted(AssemblyID assemblyId) override { return S_OK; }
        virtual HRESULT __stdcall AssemblyUnloadFinished(AssemblyID assemblyId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall ModuleLoadStarted(ModuleID moduleId) override { return S_OK; }
        virtual HRESULT __stdcall ModuleUnloadStarted(ModuleID moduleId) override { return S_OK; }
        virtual HRESULT __stdcall ModuleUnloadFinished(ModuleID moduleId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall ModuleAttachedToAssembly(ModuleID moduleId, AssemblyID AssemblyId) override { return S_OK; }
        virtual HRESULT __stdcall ClassLoadStarted(ClassID classId) override { return S_OK; }
        virtual HRESULT __stdcall ClassLoadFinished(ClassID classId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall ClassUnloadStarted(ClassID classId) override { return S_OK; }
        virtual HRESULT __stdcall ClassUnloadFinished(ClassID classId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall FunctionUnloadStarted(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall JITCompilationFinished(FunctionID functionId, HRESULT hrStatus, BOOL fIsSafeToBlock) override { return S_OK; }
        virtual HRESULT __stdcall JITCachedFunctionSearchStarted(FunctionID functionId, BOOL* pbUseCachedFunction) override { return S_OK; }
        virtual HRESULT __stdcall JITCachedFunctionSearchFinished(FunctionID functionId, COR_PRF_JIT_CACHE result) override { return S_OK; }
        virtual HRESULT __stdcall JITFunctionPitched(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall JITInlining(FunctionID callerId, FunctionID calleeId, BOOL* pfShouldInline) override { return S_OK; }
        virtual HRESULT __stdcall ThreadCreated(ThreadID threadId) override { return S_OK; }
        virtual HRESULT __stdcall ThreadAssignedToOSThread(ThreadID managedThreadId, DWORD osThreadId) override { return S_OK; }
        virtual HRESULT __stdcall RemotingClientInvocationStarted() override { return S_OK; }
        virtual HRESULT __stdcall RemotingClientSendingMessage(GUID* pCookie, BOOL fIsAsync) override { return S_OK; }
        virtual HRESULT __stdcall RemotingClientReceivingReply(GUID* pCookie, BOOL fIsAsync) override { return S_OK; }
        virtual HRESULT __stdcall RemotingClientInvocationFinished(void) override { return S_OK; }
        virtual HRESULT __stdcall RemotingServerReceivingMessage(GUID* pCookie, BOOL fIsAsync) override { return S_OK; }
        virtual HRESULT __stdcall RemotingServerInvocationStarted() override { return S_OK; }
        virtual HRESULT __stdcall RemotingServerInvocationReturned() override { return S_OK; }
        virtual HRESULT __stdcall RemotingServerSendingReply(GUID* pCookie, BOOL fIsAsync) override { return S_OK; }
        virtual HRESULT __stdcall UnmanagedToManagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason) override { return S_OK; }
        virtual HRESULT __stdcall ManagedToUnmanagedTransition(FunctionID functionId, COR_PRF_TRANSITION_REASON reason) override { return S_OK; }
        virtual HRESULT __stdcall RuntimeSuspendStarted(COR_PRF_SUSPEND_REASON suspendReason) override { return S_OK; }
        virtual HRESULT __stdcall RuntimeSuspendFinished() override { return S_OK; }
        virtual HRESULT __stdcall RuntimeSuspendAborted() override { return S_OK; }
        virtual HRESULT __stdcall RuntimeResumeStarted() override { return S_OK; }
        virtual HRESULT __stdcall RuntimeResumeFinished() override { return S_OK; }
        virtual HRESULT __stdcall RuntimeThreadSuspended(ThreadID threadId) override { return S_OK; }
        virtual HRESULT __stdcall RuntimeThreadResumed(ThreadID threadId) override { return S_OK; }
        virtual HRESULT __stdcall MovedReferences(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], ULONG cObjectIDRangeLength[]) override { return S_OK; }
        virtual HRESULT __stdcall ObjectAllocated(ObjectID objectId, ClassID classId) override { return S_OK; }
        virtual HRESULT __stdcall ObjectReferences(ObjectID objectId, ClassID classId, ULONG cObjectRefs, ObjectID objectRefIds[]) override { return S_OK; }
        virtual HRESULT __stdcall ObjectsAllocatedByClass(ULONG cClassCount, ClassID classIds[], ULONG cObjects[]) override { return S_OK; }
        virtual HRESULT __stdcall RootReferences(ULONG cRootRefs, ObjectID rootRefIds[]) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionThrown(ObjectID thrownObjectId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionSearchFunctionEnter(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionSearchFunctionLeave() override { return S_OK; }
        virtual HRESULT __stdcall ExceptionSearchFilterEnter(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionSearchFilterLeave() override { return S_OK; }
        virtual HRESULT __stdcall ExceptionSearchCatcherFound(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionOSHandlerEnter(UINT_PTR __unused) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionOSHandlerLeave(UINT_PTR __unused) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionUnwindFunctionEnter(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionUnwindFunctionLeave() override { return S_OK; }
        virtual HRESULT __stdcall ExceptionUnwindFinallyEnter(FunctionID functionId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionUnwindFinallyLeave() override { return S_OK; }
        virtual HRESULT __stdcall ExceptionCatcherEnter(FunctionID functionId, ObjectID objectId) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionCatcherLeave() override { return S_OK; }
        virtual HRESULT __stdcall COMClassicVTableCreated(ClassID wrappedClassId, REFGUID implementedIID, void* pVTable, ULONG cSlots) override { return S_OK; }
        virtual HRESULT __stdcall COMClassicVTableDestroyed(ClassID wrappedClassId, REFGUID implementedIID, void* pVTable) override { return S_OK; }
        virtual HRESULT __stdcall ExceptionCLRCatcherFound() override { return S_OK; }
        virtual HRESULT __stdcall ExceptionCLRCatcherExecute() override { return S_OK; }

        // Unimplemented ICorProfilerCallback2
        virtual HRESULT __stdcall FinalizeableObjectQueued(DWORD finalizerFlags, ObjectID objectID) override { return S_OK; }
        virtual HRESULT __stdcall GarbageCollectionFinished(void) override { return S_OK; }
        virtual HRESULT __stdcall GarbageCollectionStarted(int cGenerations, BOOL generationCollected[], COR_PRF_GC_REASON reason) override { return S_OK; }
        virtual HRESULT __stdcall HandleCreated(GCHandleID handleId, ObjectID initialObjectId) override { return S_OK; }
        virtual HRESULT __stdcall HandleDestroyed(GCHandleID handleId) override { return S_OK; }
        virtual HRESULT __stdcall RootReferences2(ULONG cRootRefs, ObjectID rootRefIds[], COR_PRF_GC_ROOT_KIND rootKinds[], COR_PRF_GC_ROOT_FLAGS rootFlags[], UINT_PTR rootIds[]) override { return S_OK; }
        virtual HRESULT __stdcall SurvivingReferences(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], ULONG cObjectIDRangeLength[]) override { return S_OK; }
        virtual HRESULT __stdcall ThreadNameChanged(ThreadID threadId, ULONG cchName, _In_reads_opt_(cchName) WCHAR name[]) override { return S_OK; }

        // Unimplemented ICorProfilerCallback3
        virtual HRESULT __stdcall InitializeForAttach(IUnknown* pCorProfilerInfoUnk, void* pvClientData, UINT cbClientData) override { return S_OK; }
        virtual HRESULT __stdcall ProfilerAttachComplete(void) override { return S_OK; }
        virtual HRESULT __stdcall ProfilerDetachSucceeded(void) override { return S_OK; }

        // Unimplemented ICorProfilerCallback4
        virtual HRESULT __stdcall ReJITCompilationFinished(FunctionID functionId, ReJITID rejitId, HRESULT hrStatus, BOOL fIsSafeToBlock) override { return S_OK; }
        virtual HRESULT __stdcall ReJITError(ModuleID moduleId, mdMethodDef methodId, FunctionID functionId, HRESULT hrStatus) override { return S_OK; }
        virtual HRESULT __stdcall MovedReferences2(ULONG cMovedObjectIDRanges, ObjectID oldObjectIDRangeStart[], ObjectID newObjectIDRangeStart[], SIZE_T cObjectIDRangeLength[]) override { return S_OK; }
        virtual HRESULT __stdcall SurvivingReferences2(ULONG cSurvivingObjectIDRanges, ObjectID objectIDRangeStart[], SIZE_T cObjectIDRangeLength[]) override { return S_OK; }

        // Base profiler initialization method
        virtual HRESULT __stdcall Initialize(IUnknown* pICorProfilerInfoUnk) override
        {
            LOG_INFO("ProfilerBase Initialize");
            return S_OK;
        }

        virtual HRESULT __stdcall ModuleLoadFinished(ModuleID moduleId, HRESULT hrStatus) override
        {
            LOG_INFO("ProfilerBase ModuleLoadFinished");
            return S_OK;
        }

        virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject) override
        {
            if (
                riid == __uuidof(ICorProfilerCallback4) || riid == __uuidof(ICorProfilerCallback3) || riid == __uuidof(ICorProfilerCallback2) || riid == __uuidof(ICorProfilerCallback)
                // || riid == IID_IUnknown
                )
            {
                *ppvObject = this;
                this->AddRef();
                return S_OK;
            }
            LOG_INFO("ProfilerBase QueryInterface riid[0X%08X]", riid);
            *ppvObject = nullptr;
            return E_NOINTERFACE;
        }

        virtual ULONG STDMETHODCALLTYPE AddRef() override
        {
            auto result = std::atomic_fetch_add(&this->_referenceCount, 1) + 1;
            LOG_INFO("ProfilerBase AddRef[%lu]", result);
            return result;
        }

        virtual ULONG STDMETHODCALLTYPE Release() override
        {
            int count = std::atomic_fetch_sub(&this->_referenceCount, 1) - 1;
            LOG_INFO("ProfilerBase Release[%d]", count);
            if (count <= 0) {
                delete this;
            }
            return count;
        }

        // ICorProfilerCallback
        virtual HRESULT __stdcall JITCompilationStarted(FunctionID functionId, BOOL /*fIsSafeToBlock*/) override
        {
            return S_OK;
        }

        virtual HRESULT __stdcall ReJITCompilationStarted(FunctionID functionId, ReJITID /*rejitId*/, BOOL /*fIsSafeToBlock*/) override
        {
            return S_OK;
        }

        virtual HRESULT __stdcall GetReJITParameters(ModuleID moduleId, mdMethodDef methodId, ICorProfilerFunctionControl* pFunctionControl) override
        {
            return S_OK;
        }

        virtual HRESULT __stdcall Shutdown() override
        {
            return S_OK;
        }

        // ICorProfilerCallback
        virtual HRESULT __stdcall ThreadDestroyed(ThreadID threadId) override
        {
            return S_OK;
        }

    protected:
        DWORD _eventMask = 0
            | COR_PRF_MONITOR_JIT_COMPILATION
            | COR_PRF_MONITOR_MODULE_LOADS
            | COR_PRF_USE_PROFILE_IMAGES
            | COR_PRF_MONITOR_THREADS
            | COR_PRF_ENABLE_STACK_SNAPSHOT
            | COR_PRF_ENABLE_REJIT
            | (DWORD)COR_PRF_DISABLE_ALL_NGEN_IMAGES
            ;
    };
}
}
