출처 - https://www.youtube.com/watch?v=SbaiAQDUi9A&list=PLDV-cCQnUlIY1jymMNofAvUdXJ75Ws5Iy&index=11&ab_channel=%EC%BD%94%EB%93%9C%EC%97%86%EB%8A%94%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D

memory split -> false sharing(because chcheline(64k) sync) -> padding solution
mutex.try_lock() -> lock 실패하면 바로 통과(wait하지 않음)
mutex.unlock() -> 대기하던 어떤 쓰레드가 획득할지 모름
std::scoped_lock() -> RAII(Resource Acquisition is Initialization) <- smart pointer 개념
recursive_mutex, unique_lock, shard_lock
condition variable -> spurious wakeup
