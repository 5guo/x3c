/*! \file ReadInts.h
 *  \brief ����Ӵ��з������������ĺ��� ReadInts �� ReadDoubleArray
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef UTILFUNC_READINTS_H_
#define UTILFUNC_READINTS_H_

//! ����һ���ַ��Ƿ�Ϊ�γ��������ַ�
/*!
    \param c Ҫ�����ַ�
    \param signchar �����Ƿ�������������ţ����Ϊfalse�����Ϊ���ֲŷ���true
    \return �Ƿ�Ϊ�γ��������ַ�
*/
inline bool IsIntChar(wchar_t c, bool signchar = false)
{
    return iswdigit(c) || signchar && ('+' == c || '-' == c);
}

//! ���ַ����з�����������
/*!
    \ingroup _GROUP_UTILFUNC
    \param[in] str ��������������ַ������ñ����š��հ׵��ַ��ָ�
    \param[out] arr �����������������size������
    \param[in] size ��������ٸ�����������arr��Ԫ�ظ���
    \param[in] signchar �����Ƿ�������������ţ����Ϊfalse�����Ϊ���ֲŷ���true
    \return ���������������
    \see IsIntChar
*/
template <class IntType> inline
long ReadInts(const wchar_t* str, IntType* arr, long size, bool signchar = false)
{
    if (NULL == str)
    {
        return 0;
    }

    int i, j, count;
    wchar_t buf[13];

    for (i = 0, count = 0; str[i] != 0 && count < size; )
    {
        while (str[i] != 0 && !IsIntChar(str[i], signchar))
        {
            i++;
        }
        for (j = i; IsIntChar(str[j], signchar); j++)
        {
        }
        if (j > i)
        {
            lstrcpynW(buf, str + i, min(_countof(buf), 1 + j - i));
            arr[count++] = static_cast<IntType>(_wtoi(buf));
        }
        i = j;
    }

    return count;
}

//! ����һ���ַ��Ƿ�Ϊ�γɸ��������ַ�
inline bool IsDblChar(wchar_t c)
{
    return iswdigit(c) || '+' == c || '-' == c
        || '.' == c || 'E' == c || 'e' == c;
}

//! ���ַ����з�������������
/*!
    \ingroup _GROUP_UTILFUNC
    \param[in] str ����������������ַ������ñ����š��հ׵��ַ��ָ�
    \param[out] arr �������������������size��������
    \param[in] size ��������ٸ�������������arr��Ԫ�ظ���
    \return ������ĸ���������
    \see IsDblChar
*/
inline long ReadDoubleArray(const wchar_t* str, double* arr, long size)
{
    if (NULL == str)
    {
        return 0;
    }

    int i, j, count;
    wchar_t buf[32];
    wchar_t* endptr;

    for (i = 0, count = 0; str[i] != 0 && count < size; )
    {
        while (str[i] != 0 && !IsDblChar(str[i]))
        {
            i++;
        }
        for (j = i; IsDblChar(str[j]); j++)
        {
        }
        if (j > i)
        {
            lstrcpynW(buf, str + i, min(32, 1 + j - i));
            arr[count++] = wcstod(buf, &endptr);
        }
        i = j;
    }

    return count;
}

#endif // UTILFUNC_READINTS_H_
