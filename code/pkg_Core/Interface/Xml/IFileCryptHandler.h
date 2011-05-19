/*! \file IFileCryptHandler.h
 *  \brief �����ļ����ݼӽ��ܵĽӿ� IFileCryptHandler
 *  \author Zhang Yun Gui, X3 C++ PluginFramework
 *  \date   2010.10.22
 */
#ifndef X3_IFILECRYPTHANDLER_H_
#define X3_IFILECRYPTHANDLER_H_

//! �ļ����ݼӽ��ܵĽӿ�
interface IFileCryptHandler
{
    //! ��һ�������ļ��еõ��ļ�����
    /*!
        \param[in] filename �Ѽ����ļ����ļ�ȫ��
        \param[out] buffer ����ļ����ݣ��� FreeBuffer �ͷ�
        \return 0 ��ʾִ�гɹ��������ʾʧ��
    */
    virtual int Decrypt(const wchar_t* filename, wchar_t** buffer) = 0;

    //! �ͷ��� Decrypt ������ڴ���Դ
    virtual void FreeBuffer(wchar_t* buffer) = 0;

    //! ��һ���������ݵ��ļ����м���
    /*! 
        \param srcfile ���������ļ����ļ�ȫ��
        \param destfile �����ļ����ļ�ȫ��
        \return 0 ��ʾִ�гɹ��������ʾʧ��
    */
    virtual int CryptFile(const wchar_t* srcfile, const wchar_t* destfile) = 0;
};

#endif // X3_IFILECRYPTHANDLER_H_
