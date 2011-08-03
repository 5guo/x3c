// dllmain.h : Declaration of module class.

class CoreComModule : public CAtlPluginT< CoreComModule >
{
public:
    DECLARE_LIBID(LIBID_X3Core)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_X3CORECOM, "{BE7C1B6B-BE1B-455F-B09C-DD9951B63968}")
    DECLARE_PLUGINS(true, L"", L"")
};

extern class CoreComModule _AtlModule;