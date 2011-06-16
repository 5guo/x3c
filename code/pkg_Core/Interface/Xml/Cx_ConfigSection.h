/*! \file Cx_ConfigSection.h
 *  \brief �������ö�д�ӿڵķ�װ�� Cx_ConfigSection
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_XML_CONFIGIOSECTION_H_
#define X3_XML_CONFIGIOSECTION_H_

#include "Ix_ConfigData.h"

//! ���ö�д�ӿڵķ�װ�࣬��Ӧ��һ�����ݽڵ�
/*! ���ӿ������������ݶ����൱��������״��νṹ�е�һ�����ݽڵ㣬
    �� Ix_ConfigData ���Ӧ��ȫ�����ݽڵ㡣
    \ingroup _GROUP_PLUGIN_XML_
*/
class Cx_ConfigSection : public Cx_Interface<Ix_ConfigSection>
{
public:
    //! ���캯��
    Cx_ConfigSection()
    {
    }

    //! �������캯��
    Cx_ConfigSection(const Cx_Interface<Ix_ConfigSection>& src)
        : Cx_Interface<Ix_ConfigSection>(src)
    {
    }

    //! ��Cx_Ptr����
    Cx_ConfigSection(const Cx_Ptr& objConfigIO)
    {
        Cx_Interface<Ix_ConfigSection> pIFSec(objConfigIO);
        if (pIFSec.IsNotNull())
        {
            Cx_Interface<Ix_ConfigSection>::operator=(pIFSec);
        }
    }

    //! ��ֵ����������
    Cx_ConfigSection& operator=(const Cx_Interface<Ix_ConfigSection>& src)
    {
        if (&src != this)
        {
            Cx_Interface<Ix_ConfigSection>::operator=(src);
        }
        return *this;
    }

    //! ��������
    virtual ~Cx_ConfigSection()
    {
        Release();
    }

    //! �õ�һ�������ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    Cx_ConfigSection GetSection(
        const wchar_t* name, bool autoCreate = true) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSection(P(), name, L"", L"", autoCreate);
    }

    //! �õ���������ʶ���Բ�����һ�����ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    Cx_ConfigSection GetSection(const wchar_t* name,
        const wchar_t* attrName, ULONG attrValue, bool autoCreate = true) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSection(P(), name, attrName, attrValue, autoCreate);
    }

    //! �õ������Բ�����һ�����ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    Cx_ConfigSection GetSection(const wchar_t* name,
        const wchar_t* attrName, const wchar_t* attrValue,
        bool autoCreate = true) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSection(P(), name, attrName, attrValue, autoCreate);
    }

    //! �õ������Բ�����һ�����ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ�ĵ�һ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param attrName2 ��ʶһ�������ݽڵ�ĵڶ�����������
        \param attrValue2 �ñ�ʶ���Ӧ��attrName2������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    Cx_ConfigSection GetSection(const wchar_t* name,
        const wchar_t* attrName, const wchar_t* attrValue,
        const wchar_t* attrName2, const wchar_t* attrValue2,
        bool autoCreate = true) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSection(P(), name, attrName, attrValue,
            attrName2, attrValue2, autoCreate);
    }

    //! �õ���������ʶ���Բ�����һ�����ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ�ĵ�һ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param attrName2 ��ʶһ�������ݽڵ�ĵڶ�����������
        \param attrValue2 �ñ�ʶ���Ӧ��attrName2������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    Cx_ConfigSection GetSection(const wchar_t* name,
        const wchar_t* attrName, ULONG attrValue,
        const wchar_t* attrName2, ULONG attrValue2,
        bool autoCreate = true)
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSection(P(), name, attrName, attrValue,
            attrName2, attrValue2, autoCreate);
    }

    //! �õ��ڵ�����Ӧ���ӽڵ����
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \return �����ݽڵ�ĸ���
        \see GetSectionByIndex
    */
    long GetSectionCount(const wchar_t* name) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSectionCount(P(), name);
    }

    //! �ڽڵ�����Ӧ���ӽڵ��еõ�ָ����ŵ������ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param index Ҫȡ�������ݽڵ�����
        \return �µ����ݽڵ㣬�����������Ըö���Ķ�д���������ԣ������� IsValid() ������Ƿ�Ϊ��Ч�ڵ�
        \see GetSectionCount
    */
    Cx_ConfigSection GetSectionByIndex(const wchar_t* name, long index) const
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetSectionByIndex(P(), name, index);
    }

    //! ���һ�����ݽڵ�
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \return �µ����ݽڵ�
    */
    Cx_ConfigSection AddSection(const wchar_t* name)
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->AddSection(P(), name);
    }

    //! ɾ�������ݽڵ�������ӽڵ�
    /*!
        \param name �ӽڵ����ݽڵ����ƣ����ܰ�����б�Ż�б��
        \param attrName �ӽڵ�ı�ʶ����������ѡֵ
        \param attrValue ��ʶ��������Ӧ��ֵ��attrName��Ϊ��ʱ��Ч
        \return ɾ�����ӽڵ����
    */
    long RemoveChildren(const wchar_t* name, const wchar_t* attrName = L"", const wchar_t* attrValue = L"")
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->RemoveChildren(P(), name, attrName, attrValue);
    }

    //! ɾ�������ݽڵ�������ӽڵ�
    /*!
        \param name �ӽڵ����ݽڵ����ƣ����ܰ�����б�Ż�б��
        \param attrName �ӽڵ�ı�ʶ����������Ϊ��
        \param attrValue ��ʶ������attrName��Ӧ��ֵ
        \return ɾ�����ӽڵ����
    */
    long RemoveChildren(const wchar_t* name, const wchar_t* attrName, ULONG attrValue)
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->RemoveChildren(P(), name, attrName, attrValue);
    }

    //! �õ���һ���ڵ�
    /*! ������ڵ�Ϊ���ڵ㣬�򷵻ؽڵ�Ϊ��Ч�ڵ�(IsValid()==false)
        \return ��һ�����ݽڵ����
    */
    Cx_ConfigSection GetParentSection()
    {
        Ix_ConfigData* pIFData = P()->GetData();
        return pIFData->GetParentSection(P());
    }
};

#endif // X3_XML_CONFIGIOSECTION_H_
