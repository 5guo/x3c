/*! \file Ix_ConfigData.h
 *  \brief �����������ݽӿ� Ix_ConfigData
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_XML_ICONFIGDATA_H_
#define X3_XML_ICONFIGDATA_H_

#include "Ix_ConfigSection.h"

//! �������ݽӿ�
/*! ���ӿ������������ݶ����൱��������״��νṹ�е�ȫ�����ݽڵ㣬
    �� Cx_ConfigSection ���Ӧ��һ�����ݽڵ㡣\n
    ���������ʹ�� Cx_ConfigTransaction ת��������ͱ��档
    \interface Ix_ConfigData
    \ingroup _GROUP_PLUGIN_XML_
*/
class Ix_ConfigData
{
public:
    virtual ~Ix_ConfigData() {}

    //! һ�����ݽڵ㣬ͬ������ Cx_ConfigSection
    typedef Cx_Interface<Ix_ConfigSection> ConfigSection;

    //! �õ����ڵ��µ�һ�����ݽڵ����
    /*!
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶����·��.
            Ϊ�մ��򷵻ظ��ڵ�����ݽڵ�
        \param autoCreate ������ʱ�Ƿ��Զ�������ݽڵ�
        \return �µ����ݽڵ㣬������ʱ����autoCreate�Զ����
    */
    virtual ConfigSection GetSection(
        const wchar_t* name, bool autoCreate = true) = 0;
    
    //! �õ���������ʶ���Բ�����һ�����ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ�������ݽڵ�
        \return �µ����ݽڵ㣬���������Զ����
    */
    virtual ConfigSection GetSection(
        Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName, ULONG attrValue, 
        bool autoCreate = true) = 0;

    //! �õ������Բ�����һ�����ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    virtual ConfigSection GetSection(
        Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName, const wchar_t* attrValue, 
        bool autoCreate = true) = 0;

    //! �õ������Բ�����һ�����ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ�ĵ�һ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param attrName2 ��ʶһ�������ݽڵ�ĵڶ�����������
        \param attrValue2 �ñ�ʶ���Ӧ��attrName2������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    virtual ConfigSection GetSection(
        Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName, const wchar_t* attrValue, 
        const wchar_t* attrName2, const wchar_t* attrValue2, 
        bool autoCreate = true) = 0;

    //! �õ���������ʶ���Բ�����һ�����ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param attrName ��ʶһ�������ݽڵ�ĵ�һ����������
        \param attrValue �ñ�ʶ���Ӧ������ֵ
        \param attrName2 ��ʶһ�������ݽڵ�ĵڶ�����������
        \param attrValue2 �ñ�ʶ���Ӧ��attrName2������ֵ
        \param autoCreate ������ʱ�Ƿ��Զ����
        \return �µ����ݽڵ㣬���������Զ����
    */
    virtual ConfigSection GetSection(
        Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName, ULONG attrValue, 
        const wchar_t* attrName2, ULONG attrValue2, 
        bool autoCreate = true) = 0;

    //! �õ��ڵ�����Ӧ���ӽڵ����
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \return �����ݽڵ�ĸ���
        \see GetSectionByIndex
    */
    virtual long GetSectionCount(
        Ix_ConfigSection* parent, const wchar_t* name) = 0;

    //! �ڽڵ�����Ӧ���ӽڵ��еõ�ָ����ŵ������ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \param index Ҫȡ�������ݽڵ�����
        \return �µ����ݽڵ㣬�����������Ըö���Ķ�д���������ԣ������� IsValid() ������Ƿ�Ϊ��Ч�ڵ�
        \see GetSectionCount
    */
    virtual ConfigSection GetSectionByIndex(
        Ix_ConfigSection* parent, const wchar_t* name, long index) = 0;
    
    //! ���һ�����ݽڵ�
    /*!
        \param parent ��һ�������ݽڵ㣬ΪNULL��ȡ���ڵ�
        \param name ���ݽڵ����ƣ�����б�Ż�б�ŷָ��༶���·��
        \return �µ����ݽڵ�
    */
    virtual ConfigSection AddSection(
        Ix_ConfigSection* parent, const wchar_t* name) = 0;

    //! ɾ��һ�����ݽڵ�
    /*!
        \param sec Ҫɾ�������ݽڵ����ֻ������ڲ����ݣ����ͷŸö���
        \return �Ƿ�ɾ���ɹ�
    */
    virtual bool RemoveSection(Ix_ConfigSection* sec) = 0;
    
    //! ɾ��ָ�������ݽڵ�������ӽڵ�
    /*!
        \param parent Ҫɾ���ڵ����һ�����ݽڵ�
        \param name �ӽڵ����ƣ����ܰ�����б�Ż�б��
        \param attrName �ӽڵ�ı�ʶ����������ѡֵ
        \param attrValue ��ʶ��������Ӧ��ֵ��attrName��Ϊ��ʱ��Ч
        \return ɾ�����ӽڵ����
    */
    virtual long RemoveChildren(Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName = L"", const wchar_t* attrValue = L"") = 0;

    //! ɾ��ָ�������ݽڵ�������ӽڵ�
    /*!
        \param parent Ҫɾ���ڵ����һ�����ݽڵ�
        \param name �ӽڵ����ƣ����ܰ�����б�Ż�б��
        \param attrName �ӽڵ�ı�ʶ����������Ϊ��
        \param attrValue ��ʶ������attrName��Ӧ��ֵ
        \return ɾ�����ӽڵ����
    */
    virtual long RemoveChildren(Ix_ConfigSection* parent, const wchar_t* name, 
        const wchar_t* attrName, ULONG attrValue) = 0;

    //! �õ�һ�����ݽڵ����һ���ڵ�
    /*!
        \param sec ָ�������ݽڵ����
        \return ��һ�����ݽڵ�������secΪ���ڵ㣬�򷵻ؽڵ�Ϊ��Ч�ڵ�(IsValid()==false)
    */
    virtual ConfigSection GetParentSection(Ix_ConfigSection* sec) = 0;
};

#endif // X3_XML_ICONFIGDATA_H_
