building original constant-q-cpp for linux

cp Makefile.linux Makefile
ln -s /usr/lib/x86_64-linux-gnu/ ../vamp-plugin-sdk
apt-get install vamp-plugin-sdk libsndfile1-dev libboost-test-dev
make


