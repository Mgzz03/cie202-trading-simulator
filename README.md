# CIE202 Trading Simulator

A C++ event-driven trading simulation that models accounts, brokers, orders, stocks, market data, portfolios, wallets, transactions, and backtesting.

## Domain Model

| Component | Role |
| --- | --- |
| `Market` and `Stock` | Market data and tradable instruments |
| `Order` and `OrderBook` | Order submission and matching structures |
| `Broker` and `CommissionCalculator` | Trade execution and fees |
| `Account`, `Wallet`, and `Portfolio` | User holdings and balances |
| `EventDrivenTrading` | Simulation orchestration |
| `Backtester` and `Prediction` | Strategy evaluation support |

## Build

Open `Project.vcxproj` with Visual Studio and build the project using the C++ desktop workload. The source is published for portfolio review; no investment or trading advice is provided, and the simulator is not connected to a live brokerage.
