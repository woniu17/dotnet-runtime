#include "inc/openum.h"
#include "ildasm/dis.h"
#include "ildasm/ceeload.h"
#include "pal/init.h"

bool hellocoreclr()
{
    PAL_InitializeWithFlags(PAL_INITIALIZE_STD_HANDLES);
    unsigned uConsoleCP = CP_ACP;
    const char *pszFilename = "/root/publish/hello-dotnet/hello-dotnet.dll";
    WCHAR wzInputFileName[MAX_FILENAME_LENGTH];
    char szFilenameANSI[MAX_FILENAME_LENGTH*3];
    memset(wzInputFileName, 0, sizeof(WCHAR)*MAX_FILENAME_LENGTH);
    WszMultiByteToWideChar(CP_UTF8, 0, pszFilename,-1, wzInputFileName, MAX_FILENAME_LENGTH);
    memset(szFilenameANSI, 0, MAX_FILENAME_LENGTH*3);
    WszWideCharToMultiByte(uConsoleCP, 0,wzInputFileName, -1, szFilenameANSI, MAX_FILENAME_LENGTH * 3, NULL, NULL);
    auto peLoader = new PELoader();
    auto fSuccess = peLoader->open(wzInputFileName);
    printf("open[%s] result[%d]\n", pszFilename, fSuccess);
    if (fSuccess == FALSE)
    {
        return TRUE;
    }
    IMAGE_COR20_HEADER * corHeader = NULL;
    if (peLoader->getCOMHeader(&corHeader) == FALSE)
    {
        return TRUE;
    }
    void * pMetaData = NULL;
    unsigned cbMetaData = 0;
    if (peLoader->getVAforRVA(VAL32(corHeader->MetaData.VirtualAddress), &pMetaData) == FALSE)
    {
        return TRUE;
    }
    cbMetaData = VAL32(corHeader->MetaData.Size);
    printf("pMetaData[%p]\n", pMetaData);
    printf("cbMetaData[%d]\n", cbMetaData);
    if (VAL16(corHeader->MajorRuntimeVersion) == 1
        || VAL16(corHeader->MajorRuntimeVersion) > COR_VERSION_MAJOR)
    {
        return TRUE;
    }
    mdMethodDef tkEntryPoint = 0; // integration with ILDASM
    tkEntryPoint = VAL32(IMAGE_COR20_HEADER_FIELD(*corHeader, EntryPointToken)); // integration 
    DWORD openFlags = ofRead | ofNoTransform;
    IMDInternalImport*      pImport = NULL;
    IMetaDataImport2*        pPubImport = NULL;
    IMetaDataAssemblyImport* pAssemblyImport = NULL;
    IMetaDataDispenser *pMetaDataDispenser = NULL;
    if (FAILED(GetMetaDataInternalInterface(
        (BYTE *)pMetaData,
        cbMetaData,
        openFlags,
        IID_IMDInternalImport,
        (LPVOID *)&pImport)))
    {
        return TRUE;
    }
    // TokenSigInit(pImport);
    if (FAILED(MetaDataGetDispenser(CLSID_CorMetaDataDispenser,
        IID_IMetaDataDispenser, (LPVOID*)&pMetaDataDispenser)))
    {
        return TRUE;
    }

    if (FAILED(pMetaDataDispenser->OpenScopeOnMemory(pMetaData,
        cbMetaData, openFlags, IID_IMetaDataImport2, (LPUNKNOWN *)&pPubImport )))
    {
        return TRUE;
    }

    char*       rchCA = NULL; // dyn.allocated array of CA dumped/not flags
    unsigned    uNCA = 0;     // num. of CAs
    if((uNCA = pImport->GetCountWithTokenKind(mdtCustomAttribute)))
    {
        rchCA = new char[uNCA + 1];
        _ASSERTE(rchCA);
    }
    printf("pMetaDataDispenser[%p]\n", pMetaDataDispenser);
    printf("pImport[%p]\n", pImport);
    printf("pPubImport[%p]\n", pPubImport);
    printf("pAssemblyImport[%p]\n", pAssemblyImport);
    printf("pMetaDataDispenser[%p]\n", pMetaDataDispenser);
    // EnumClasses();
    // EnumTypedefs();
    return TRUE;
}