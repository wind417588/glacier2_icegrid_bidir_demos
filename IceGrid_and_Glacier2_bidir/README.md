1. make clean;make -j8
2. 在独立的窗口运行 nohup icegridregistry --Ice.Config=registry.cfg &
3. 在独立的窗口运行 icegridnode --Ice.Config=node.cfg
4. 在独立的窗口运行 glacier2router --Ice.Config=config.glacier2
5. 在独立的窗口运行 ./client
6. 对于client/server而言，若果想调试请打开Ice.Trace.Network和Ice.Trace.Protocol这两个开关
7. 对于glacier2而言,需要打开如下开关:
  Ice.Trace.Protocol, Ice.Trace.Network, Ice.Trace.Locator, Glacier2.Client.Trace.Request, Glacier2.Server.Trace.Request, Glacier2.Client.Trace.Override, Glacier2.Server.Trace.Override, Glacier2.Client.Trace.Reject, Glacier2.Trace.Session, Glacier2.Trace.RoutingTable
