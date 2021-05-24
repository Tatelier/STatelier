using System;
using System.Runtime.InteropServices;

namespace STatelier
{
	class Program
	{
		[DllImport("Tatelier.Nucleus.dll", EntryPoint = "Start")]
		extern static void TatelierStart();

		[DllImport("Tatelier.Nucleus.dll", EntryPoint = "Run")]
		extern static void TatelierRun();

		[DllImport("Tatelier.Nucleus.dll", EntryPoint = "Finish")]
		extern static void TatelierFinish();

		static void Main(string[] args)
		{
			TatelierStart();
			TatelierRun();
			TatelierFinish();
		}
	}
}
