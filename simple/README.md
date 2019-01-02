1. make clean;make -j8
2. 在独立的窗口运行nohup icegridregistry --Ice.Config=registry.cfg &
3. 在独立的窗口运行icegridnode --Ice.Config=node.cfg
4. 在独立的窗口运行./client
