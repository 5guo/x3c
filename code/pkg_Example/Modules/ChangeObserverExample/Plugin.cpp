#include "stdafx.h"
#include "DocObserverTest.h"

static CDocObserverTestOnRun* s_observer = NULL;

// ����б����������ڲ������ʱ�ɲ�����������ã�����ע��ȹؼ���ʼ������
extern "C" __declspec(dllexport) bool InitializePlugin()
{
    s_observer = new CDocObserverTestOnRun;
    return true;
}

// ����б����������ڲ��ж��ǰ�ɲ�����������ã������ͷ���Դ��ע������
extern "C" __declspec(dllexport) void UninitializePlugin()
{
    delete s_observer;
}
