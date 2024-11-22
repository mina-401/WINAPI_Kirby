#pragma once

// 템플릿 클래스 만들때의 팁
typedef class AActor* DataType;

class ActorVector
{
    // 헤더 CPP 분할을 하지 않겠습니다.
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

