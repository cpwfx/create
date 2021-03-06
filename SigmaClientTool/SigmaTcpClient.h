/*Copyright 2017 Bang & Olufsen A/S

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/

#pragma once

#include "SigmaDataTypes.h"
#include <string>
#include "SigmaProtocolDataFormatter.h"

class SigmaTcpClient {
public:
	SigmaTcpClient();
	~SigmaTcpClient();

	void InitializeConnection(std::string ip);

	SigmaReadResponse& ReadMemory(uint16_t addr, uint16_t size);

	void WriteMemory(uint16_t addr, uint16_t size, uint8_t* data);

	double ReadDecimal(uint16_t addr);

	void WriteDecimal(uint16_t addr, double value);

	int ReadInteger(uint16_t addr);

	void WriteInteger(uint16_t addr, int value);

	bool WriteEeprom(std::string pathToFile);

private:
	SigmaReadResponse m_readResponse;
	SigmaProtocolDataFormatter m_dataFormatter;
	int m_sockConnection;
	const double m_FullScaleIntValue = 0x1000000;
	const int m_DecimalByteSize = 4;
	const int m_IntByteSize = 4;
	static const int m_MaxRequestSize = 1024 * 2 + SigmaCommandHeaderSize;
	uint8_t m_requestDatabuffer[m_MaxRequestSize];
};