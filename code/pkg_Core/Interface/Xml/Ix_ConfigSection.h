/*! \file Ix_ConfigSection.h
 *  \brief �������ݽڵ��ֵ��д�ӿ� Ix_ConfigSection
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_XML_ICONFIGSECTION_H_
#define X3_XML_ICONFIGSECTION_H_

#include <XComPtr.h>

interface Ix_ConfigData;

//! ���ݽڵ��ֵ��д�ӿ�
/*! ��ʹ�� CConfigIOSection ���������ʹ�ñ��ӿڡ�\n
    ���ӿ������������ݶ����൱��������״��νṹ�е�һ�����ݽڵ㣬
    �� Ix_ConfigData ���Ӧ��ȫ�����ݽڵ㡣
    \interface Ix_ConfigSection
    \ingroup _GROUP_PLUGIN_XML_
    \see CConfigIOSection, Ix_ConfigData
*/
interface Ix_ConfigSection
{
    //! ����ӵ�������ù���ӿڶ���
    virtual Ix_ConfigData* GetData() const = 0;

    //! �����ڲ������Ƿ�Ϸ�
    /*!
        \return ���ڲ��Ƿ��ж�Ӧ��ʵ�����ݽڵ�
    */
    virtual bool IsValid() const = 0;

    //! �õ�ֵ����Ϊ�ַ�����������
    /*!
        \param name ������������
        \param defValue Ĭ��ֵ������û�ж�Ӧ��������ʱȡΪ��ֵ
        \return ���������ֵ
        \see SetString
    */
    virtual std::wstring GetString(const wchar_t* name, const wchar_t* defValue = L"") = 0;

    //! ����ֵ����Ϊ�ַ�����������
    /*!
        \param name ������������
        \param value �µ�ֵ
        \return �Ƿ�ı�������
        \see GetString
    */
    virtual bool SetString(const wchar_t* name, const wchar_t* value) = 0;

    //! �õ�ֵ����Ϊ������������
    /*! ���������Զ���ȡ���ġ�true���͡�false��ת��Ϊ������
        \param name ������������
        \param defValue Ĭ��ֵ����������Ϊ�մ���û��ʱȡΪ��ֵ
        \return ���������ֵ
    */
    virtual int GetInt(const wchar_t* name, int defValue = 0) = 0;

    //! ����ֵ����Ϊ������������
    /*!
        \param name ������������
        \param value �µ�ֵ
        \return �Ƿ�ı�������
    */
    virtual bool SetInt(const wchar_t* name, int value) = 0;

    //! �õ�ֵ����Ϊ��������������
    /*! ����˵���ο� GetInt()
    */
    virtual long GetInt32(const wchar_t* name, long defValue = 0) = 0;

    //! ����ֵ����Ϊ��������������
    /*! ����˵���ο� SetInt()
    */
    virtual bool SetInt32(const wchar_t* name, long value) = 0;

    //! �õ�ֵ����Ϊ�޷��ų�������������
    /*! ����˵���ο� GetInt()
    */
    virtual ULONG GetUInt32(const wchar_t* name, ULONG defValue = 0) = 0;

    //! ����ֵ����Ϊ�޷��ų�������������
    /*! ����˵���ο� SetInt()
    */
    virtual bool SetUInt32(const wchar_t* name, ULONG value) = 0;

    //! �õ�ֵ����Ϊ��������������
    /*! ����˵���ο� GetInt()
    */
    virtual short GetInt16(const wchar_t* name, short defValue = 0) = 0;

    //! ����ֵ����Ϊ��������������
    /*! ����˵���ο� SetInt()
    */
    virtual bool SetInt16(const wchar_t* name, short value) = 0;

    //! �õ�ֵ����Ϊ�޷��Ŷ�������������
    /*! ����˵���ο� GetInt()
    */
    virtual WORD GetUInt16(const wchar_t* name, WORD defValue = 0) = 0;

    //! ����ֵ����Ϊ�޷��Ŷ�������������
    /*! ����˵���ο� SetInt()
    */
    virtual bool SetUInt16(const wchar_t* name, WORD value) = 0;

    //! �õ�ֵ����Ϊ������������
    /*!
        \param name ������������
        \param defValue Ĭ��ֵ����������Ϊ�մ���û��ʱȡΪ��ֵ
        \return ���������ֵ������Ϊ��������ֵ��true��ʱ����true������Ϊfalse
    */
    virtual bool GetBool(const wchar_t* name, BOOL defValue) = 0;

    //! ����ֵ����Ϊ������������
    /*!
        \param name ������������
        \param value �µ�ֵ
        \return �Ƿ�ı�������
    */
    virtual bool SetBool(const wchar_t* name, BOOL value) = 0;

    //! �õ�ֵ����Ϊ��������������
    /*!
        \param name ������������
        \param defValue Ĭ��ֵ����������Ϊ�մ���û��ʱȡΪ��ֵ
        \return ���������ֵ
    */
    virtual double GetDouble(const wchar_t* name, double defValue = 0) = 0;

    //! ����ֵ����Ϊ��������������
    /*!
        \param name ������������
        \param value �µ�ֵ
        \return �Ƿ�ı�������
    */
    virtual bool SetDouble(const wchar_t* name, double value) = 0;

    //! �õ�ֵ����Ϊ��������������
    /*!
        ����˵���μ� GetDouble()
    */
    virtual float GetFloat(const wchar_t* name, float defValue = 0) = 0;

    //! ����ֵ����Ϊ��������������
    /*!
        ����˵���μ� SetDouble()
    */
    virtual bool SetFloat(const wchar_t* name, float value) = 0;

    //! �õ�ֵ����ΪRGB��ɫ��������
    /*!
        \param name ������������
        \param defValue Ĭ��ֵ����������û�а�����������ʱȡΪ��ֵ
        \return ���������ֵ��ʹ���� RGB(r,g,b) ��
    */
    virtual COLORREF GetRGB(const wchar_t* name, COLORREF defValue) = 0;

    //! ����ֵ����ΪRGB��ɫֵ��������
    /*!
        \param name ������������
        \param value �µ�ֵ����ȡ��6λ��������ɫ����
        \return �Ƿ�ı�������
    */
    virtual bool SetRGB(const wchar_t* name, COLORREF value) = 0;

    //! �õ�ֵ����ΪCMYK��ɫֵ��������
    /*!
        \param[in] name ������������
        \param[out] c ��ȡ�ɹ�ʱ���CMYK��ɫֵ��C���֣�ʧ��ʱ���ı���ֵ
        \param[out] m ��ȡ�ɹ�ʱ���CMYK��ɫֵ��M���֣�ʧ��ʱ���ı���ֵ
        \param[out] y ��ȡ�ɹ�ʱ���CMYK��ɫֵ��Y���֣�ʧ��ʱ���ı���ֵ
        \param[out] k ��ȡ�ɹ�ʱ���CMYK��ɫֵ��K���֣�ʧ��ʱ���ı���ֵ
        \return �Ƿ��ȡ�ɹ�
    */
    virtual bool GetCMYK(const wchar_t* name, WORD& c, WORD& m, WORD& y, WORD& k) = 0;

    //! ����ֵ����ΪCMYK��ɫֵ��������
    /*!
        \param name ������������
        \param c CMYK��ɫֵ��C����
        \param m CMYK��ɫֵ��M����
        \param y CMYK��ɫֵ��Y����
        \param k CMYK��ɫֵ��K����
        \return �Ƿ�ı�������
    */
    virtual bool SetCMYK(const wchar_t* name, WORD c, WORD m, WORD y, WORD k) = 0;

    //! �õ�ֵ����Ϊ����ֵ��������
    /*!
        \param[in] name ������������
        \param[out] year ��ȡ�ɹ�ʱ������(1980-2099)��ʧ��ʱ���ı���ֵ
        \param[out] month ��ȡ�ɹ�ʱ����·�(0-12)��ʧ��ʱ���ı���ֵ
        \param[out] day ��ȡ�ɹ�ʱ�����(0-31)��ʧ��ʱ���ı���ֵ
        \return �Ƿ��ȡ�ɹ�
    */
    virtual bool GetDate(const wchar_t* name, int& year, int& month, int& day) = 0;

    //! ����ֵ����Ϊ����ֵ��������
    /*!
        \param name ������������
        \param year ���(1980-2099)
        \param month �·�(0-12)
        \param day ��(0-31)
        \return �Ƿ�ı�������
    */
    virtual bool SetDate(const wchar_t* name, int year, int month, int day) = 0;

    //! �õ�ֵ����Ϊ����ʱ��ֵ��������
    /*!
        \param[in] name ������������
        \param[out] year ��ȡ�ɹ�ʱ������(1980-2099)��ʧ��ʱ���ı���ֵ
        \param[out] month ��ȡ�ɹ�ʱ����·�(0-12)��ʧ��ʱ���ı���ֵ
        \param[out] day ��ȡ�ɹ�ʱ�����(0-31)��ʧ��ʱ���ı���ֵ
        \param[out] hour ��ȡ�ɹ�ʱ���Сʱ(0-24)��ʧ��ʱ���ı���ֵ
        \param[out] minute ��ȡ�ɹ�ʱ������(0-60)��ʧ��ʱ���ı���ֵ
        \param[out] second ��ȡ�ɹ�ʱ�����(0-60)��ʧ��ʱ���ı���ֵ
        \return �Ƿ��ȡ�ɹ�
    */
    virtual bool GetDateTime(const wchar_t* name, int& year, int& month, int& day, 
        int& hour, int& minute, int& second) = 0;

    //! ����ֵ����Ϊ����ʱ��ֵ��������
    /*!
        \param name ������������
        \param year ���(1980-2099)
        \param month �·�(0-12)
        \param day ��(0-31)
        \param hour Сʱ(0-24)
        \param minute ����(0-60)
        \param second ��(0-60)
        \return �Ƿ�ı�������
    */
    virtual bool SetDateTime(const wchar_t* name, int year, int month, int day, 
        int hour, int minute, int second) = 0;

    //! �õ�ֵ����Ϊ�����������������
    /*!
        \param[in] name ������������
        \param[out] items Ҫ���ĸ��������飬������ count ��
        \param[in] count �����Ԫ��������
        \return ��ȡ����Ԫ�ظ����������� count
    */
    virtual long GetDoubleArray(const wchar_t* name, double* items, long count) = 0;

    //! ����ֵ����Ϊ�����������������
    /*!
        \param name ������������
        \param items Ҫ����ĸ���������
        \param count �����Ԫ�ظ���
        \return �Ƿ����óɹ�
    */
    virtual bool SetDoubleArray(const wchar_t* name, const double* items, long count) = 0;
    
    //! �õ�ֵ����Ϊ���������������
    /*!
        \param[in] name ������������
        \param[out] items Ҫ�����������飬������ count ��
        \param[in] count �����Ԫ��������
        \return ��ȡ����Ԫ�ظ����������� count
    */
    virtual long GetIntArray(const wchar_t* name, long* items, long count) = 0;

    //! ����ֵ����Ϊ���������������
    /*!
        \param name ������������
        \param items Ҫ�������������
        \param count �����Ԫ�ظ���
        \return �Ƿ����óɹ�
    */
    virtual bool SetIntArray(const wchar_t* name, const long* items, long count) = 0;
    
    //! �õ�ֵ����Ϊ�����ƻ����������
    /*!
        \param[in] name ������������
        \param[out] buf Ҫ���Ļ��壬������ size �ֽ�
        \param[in] size �������󳤶�
        \return ��ȡ���Ļ����ֽڳ��ȣ������� size
    */
    virtual long GetBinary(const wchar_t* name, LPVOID buf, long size) = 0;

    //! ����ֵ����Ϊ�����ƻ����������
    /*!
        \param name ������������
        \param buf Ҫ����Ļ���
        \param size ������ֽڳ���
        \return �Ƿ����óɹ�
    */
    virtual bool SetBinary(const wchar_t* name, LPCVOID buf, long size) = 0;
};

#endif // X3_XML_ICONFIGSECTION_H_
