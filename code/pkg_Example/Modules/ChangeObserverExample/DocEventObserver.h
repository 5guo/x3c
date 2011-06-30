//! \file DocEventObserver.h
//! \brief �����ĵ��¼��۲����� DocEventObserver

#ifndef EXAMPLE_DOCEVENT_OBSERVER_H_
#define EXAMPLE_DOCEVENT_OBSERVER_H_

#include <ChangeObserver/Cx_ChangeObserver.h>

//! �ĵ��¼�����
enum kDocEventType
{
    kDocEvent_BeforeOpen,       //!< �ĵ���֮ǰ
    kDocEvent_AfterOpen,        //!< �ĵ���֮��
    kDocEvent_OpenFail,         //!< �ĵ���ʧ��
};

//! ��Ϊ���ӵ��ĵ��¼��۲�����
/*! �����������������඼����Ӧ����¼�֪ͨ
    \note ����������ӱ���˽�м̳�
    \ingroup _GROUP_CHANGE_OBSERVER_
*/
class DocEventObserver : public Cx_ChangeObserver
{
    NOCOPY_CONSTRUCTOR(DocEventObserver);
public:
    //! DocEventObserver �۲��ߵ�֪ͨ������
    class Data : public ChangeNotifyData
    {
        NOCOPY_CONSTRUCTOR(Data);
    public:
        Data(kDocEventType _event)
            : ChangeNotifyData("DocEventObserver"), event(_event)
        {
        }

        kDocEventType event;
    };

protected:
    DocEventObserver() : Cx_ChangeObserver("DocEventObserver")
    {
    }

    //! ��Ӧ�ĵ���֮ǰ��֪ͨ
    virtual void OnDocEventBeforeOpen() {}

    //! ��Ӧ�ĵ���֮���֪ͨ
    virtual void OnDocEventAfterOpen() {}

    //! ��Ӧ�ĵ���ʧ�ܵ�֪ͨ
    virtual void OnDocEventOpenFail() {}

private:
    void DoUpdate(ChangeNotifyData* data)
    {
        Data* mydata = static_cast<Data*>(data);

        switch (mydata->event)
        {
        case kDocEvent_BeforeOpen:
            OnDocEventBeforeOpen();
            break;

        case kDocEvent_AfterOpen:
            OnDocEventAfterOpen();
            break;

        case kDocEvent_OpenFail:
            OnDocEventOpenFail();
            break;

        default:
            ASSERT(0);
        }
    }
};

#endif // EXAMPLE_DOCEVENT_OBSERVER_H_
