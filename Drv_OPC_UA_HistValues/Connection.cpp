#include"pch.h"
#include"Connection.h"

DrvOPCUAHistValues::Connection::Connection(const std::shared_ptr<IEnvironment>& environment) : m_ptrEnvironment(environment) {

}

DrvOPCUAHistValues::Connection::Connection(const std::shared_ptr<IEnvironment>& environment, const ConnectionAttributes& attributes) : m_ptrEnvironment(environment), m_connectionAttributes(attributes) {

}

DrvOPCUAHistValues::Connection::Connection(std::shared_ptr<IEnvironment>&& environment, ConnectionAttributes&& attributes) : m_ptrEnvironment(std::move(environment)), m_connectionAttributes(std::move(attributes)) {

}

DrvOPCUAHistValues::Connection::Connection(const std::shared_ptr<IEnvironment>& environment, ConnectionAttributes&& attributes) : m_ptrEnvironment(environment), m_connectionAttributes(std::move(attributes)) {

}

DrvOPCUAHistValues::Connection::Connection(std::shared_ptr<IEnvironment>&& environment) : m_ptrEnvironment(std::move(environment)) {

}

DrvOPCUAHistValues::ConnectionAttributes DrvOPCUAHistValues::Connection::GetConnectionAttributes() const
{
	return m_connectionAttributes;
}

DrvOPCUAHistValues::Connection::~Connection() {
	m_ptrEnvironment.reset();
}