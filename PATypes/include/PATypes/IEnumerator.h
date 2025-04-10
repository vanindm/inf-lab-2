#pragma once

namespace PATypes {

	template<class T>
	class IEnumerator {
	public:
		virtual bool moveNext() = 0;
		virtual T &current() {
			return *ptr;
		};
		void reset();
	private:
		T* ptr;
	};

}
