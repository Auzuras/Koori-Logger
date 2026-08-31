#include <Logging/LogChannel.h>
#include <Macros/String.h>

LogChannel::LogChannel(std::wstring _name, LogChannel* _parent)
	:m_Name(_name), m_Parent(_parent)
{}

std::wstring LogChannel::GetFullName() const
{
	std::wstring fullName = m_Name;

    for (const LogChannel* parent = m_Parent; parent != nullptr; parent = parent->m_Parent)
        fullName = parent->m_Name + L"/" + fullName;

	return fullName;
}