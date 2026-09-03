#include <Logging/LogChannel.h>
#include <Macros/String.h>

LogChannel::LogChannel(std::wstring _name, LogChannel* _parent)
	:m_Name(_name), m_Parent(_parent)
{
	m_FullName = m_Name;

	for (const LogChannel* parent = m_Parent; parent != nullptr; parent = parent->m_Parent)
		m_FullName = parent->m_Name + L"/" + m_FullName;
}