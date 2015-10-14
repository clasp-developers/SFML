export GC=boehm

setup:
	make setup-release
	make setup-debug

setup-release:
	(cd release; cmake -DCMAKE_BUILD_TYPE=Release ../..)

setup-debug:
	(cd debug; cmake -DCMAKE_BUILD_TYPE=Debug ../..)

build:
	make build-release
	make build-setup
	make install-release
	make install-setup

build-release:
	(cd release; make)

build-debug:
	(cd debug; make)

export RDEST = /home/meister/Development/clasp/build/clasp/Contents/execs/$(GC)/release/external-libs
export DDEST = /home/meister/Development/clasp/build/clasp/Contents/execs/$(GC)/debug/external-libs

install-release:
	install -d $(RDEST)
	(cd release/lib; cp * $(RDEST))

install-debug:
	install -d $(DDEST)
	(cd debug/lib; cp * $(DDEST))

clean:
	find release -type f -print -exec rm {} \; -print
	find debug -type f -print -exec rm {} \; -print
