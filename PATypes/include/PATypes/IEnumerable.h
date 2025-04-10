#pragma once

namespace PATypes {

	template<class T>
	class IEnumerable {
	public:
		virtual IEnumerator<T> getEnumerator() = 0;
	};

}
