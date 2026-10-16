array(const array& data) {
            std::cout<<"Copy constructor called"<<std::endl;
            arr = new int[10];
            for(int i = 0; i<10; i++) {
                this->arr[i] = data.arr[i];
            }
        }