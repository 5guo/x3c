//! \file NodeSelectionObserver.h
//! \brief ����ڵ�ѡ��ı�۲����� NodeSelectionObserver

#ifndef EXAMPLE_NODESELECTION_OBSERVER_H_
#define EXAMPLE_NODESELECTION_OBSERVER_H_

#include <ChangeNotifyData.h>
#include <typeinfo>

//! ��Ϊ���ӵĽڵ�ѡ��ı�۲�����
/*! �����������������඼��Ӧ�ڵ�仯�����ɱ�������ѭ���仯
    \note ����������ӱ���˽�м̳�
    \ingroup _GROUP_CHANGE_OBSERVER_
*/
class NodeSelectionObserver : public ChangeObserver
{
    NOCOPY_CONSTRUCTOR(NodeSelectionObserver);
public:
    //! NodeSelectionObserver �۲��ߵ�֪ͨ������
    class Data : public ChangeNotifyData
    {
        NOCOPY_CONSTRUCTOR(Data);
    public:
        Data(long _objid, NodeSelectionObserver* _sender)
            : ChangeNotifyData(typeid(NodeSelectionObserver).name())
            , objid(_objid), sender(_sender)
        {
        }

        long    objid;
        void*   sender;
    };

protected:
    NodeSelectionObserver() : ChangeObserver(typeid(NodeSelectionObserver).name())
    {
    }

    //! ����������Ӧ�ڵ�ѡ��ı�֪ͨ
    virtual void OnNodeSelection(long objid, void* sender)
    {
        objid; sender;
    }

private:
    void DoUpdate(ChangeNotifyData* data)
    {
        Data* mydata = dynamic_cast<Data*>(data);
        ASSERT(mydata);
        OnNodeSelection(mydata->objid, mydata->sender);
    }
};

#endif // EXAMPLE_NODESELECTION_OBSERVER_H_
