#include <PluginInc.h>

#define USE_ONE_PLUGIN
#include <XComCreator.h>

extern HMODULE g_hPluginDll;    // �� XComCreator.h

bool LoadPlugin(const wchar_t* filename);
void Test();

#if defined(_MSC_VER) && defined(UNICODE)
#define main wmain
#endif

int main()
{
    if (LoadPlugin( L"../Plugins/Win32DllTempl.plugin.dll") )
    {
        Test();

        FreeLibrary(g_hPluginDll);
        g_hPluginDll = NULL;
    }
    if (LoadPlugin( L"../Plugins/MFCExtTempl.plugin.dll") )
    {
        Test();

        FreeLibrary(g_hPluginDll);
        g_hPluginDll = NULL;
    }

    return 0;
}

bool LoadPlugin(const wchar_t* filename)
{
    g_hPluginDll = LoadLibraryW(filename);

    return g_hPluginDll != NULL;
}


#include <Ix_Example.h>

void MyFunc2(const Cx_Ptr& obj)
{
    // Cx_Interface��Cx_Ptr��ת��תΪ�ض��ӿ�
    Cx_Interface<Ix_Example> pIFExample(obj);
    if (pIFExample)
    {
        pIFExample->Foo();
    }
}

void Test()
{
    // ʹ����ID�ͽӿڴ�������
    Cx_Interface<Ix_Example> pIFExample(CLSID_Example);
    if (pIFExample)
    {
        pIFExample->Foo();    // ���ýӿں���
    }

    // ת��Ϊ�����ӿ�
    Cx_Interface<Ix_Example2> pIFExample2(pIFExample);
    if (pIFExample2.IsNotNull())
    {
        pIFExample2->Foo2();
    }

    // תΪ�޽ӿ����͵�Cx_Ptr���ɱ��⺯������ʱ������������ӿ��ļ�
    MyFunc2(Cx_Ptr(pIFExample2));
}
