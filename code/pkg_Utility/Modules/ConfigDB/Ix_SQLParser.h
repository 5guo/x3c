// Copyright 2008-2011 Zhang Yun Gui, rhcad@hotmail.com
// http://sourceforge.net/projects/x3c/

#pragma once

//! ��ͬ���ݿ��ṩԴ��SQLָ��Ľӿ�
class Ix_SQLParser
{
public:
    virtual ~Ix_SQLParser() {}

    //! ���ٱ�����
    virtual void Release() = 0;

    //! ���ص�ǰ��ϵͳ����
    virtual std::wstring GetFunc_CURDATE() = 0;

    //! ���ص�ǰ��ϵͳʱ��
    virtual std::wstring GetFunc_CURTIME() = 0;

    //! ���ص�ǰ��ϵͳ���ں�ʱ��
    virtual std::wstring GetFunc_NOW() = 0;
};
