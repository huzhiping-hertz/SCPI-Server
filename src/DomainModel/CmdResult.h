#ifndef CMDRESULT_H
#define CMDRESULT_H

#include <string>
#include <iostream>

namespace HZP
{
	using namespace std;

	class CmdResult
	{
	public:
		CmdResult(int code,string rs):m_code(code),m_rs(rs) {
		};
		static CmdResult UnRealizeCmd()
		{
			return CmdResult(-1, "Unrealize this command in this device!");
		}
	public:
		string GetResult()
		{
			return this->m_rs;
		}
		bool IsSuccess()
		{
			return this->m_code > 0;
		}
	private:
		int m_code;
		string m_rs;
	};
}
#endif
