#pragma once

// ���ø� Ŭ���� ���鶧�� ��
typedef class AActor* DataType;

class ActorVector
{
    // ��� CPP ������ ���� �ʰڽ��ϴ�.
public:
    int size() const
    {
        return DataSize;
    }

	void push_back(DataType _Data)
	{
        DataType* PrevValues = Values;
        Values = new DataType[DataSize + 1];

        for (size_t i = 0; i < DataSize; i++)
        {
            Values[i] = PrevValues[i];
        }

        if (nullptr != PrevValues)
        {
            delete[] PrevValues;
            PrevValues = nullptr;
        }

        Values[DataSize] = _Data;
        ++DataSize;
	}

    DataType& operator[](int _Index) const
    {
        return Values[_Index];
    }

private:
	DataType* Values;
	int DataSize = 0;
};

