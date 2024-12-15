#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>




// Function to get devices
const std::unordered_map<std::string, std::vector<std::string>>& getDevices() {
	// Static variable to hold devices
	static std::unordered_map<std::string, std::vector<std::string>> devices;

	// Populate the map with some devices
	devices["Output"].push_back("Printer");
	devices["Output"].push_back("Monitor");
	devices["Input"].push_back("Scanner");
	devices["Input"].push_back("Keyboard");

	return devices;  // Return a constant reference to the map
}

class Device {
public:
	Device(const std::string& name) : m_name(name) {}

	void display() const {
		std::cout << "Device Name: " << m_name << std::endl;
	}

private:
	std::string m_name;
};

// DeviceManager class definition
class DeviceManager {
public:
	// Add a device to the manager
	void addDevice(const std::string& category, Device* device) {
		m_devices[category].push_back(device);
	}

	// Constant method to get devices
	const std::unordered_map<std::string, std::vector<Device*>>& getDevices() const {
		return m_devices;
	}

private:
	std::unordered_map<std::string, std::vector<Device*>> m_devices;
};

std::string getName() {
	return "Test Name";
}

//int main() {
	//int a = 5;

	//auto b = a;

	//auto name = getName();

	//std::vector<std::string> strings;
	//strings.push_back("Apple");
	//strings.push_back("Orange");

	//for (auto v: strings)
	//{
	//	std::cout << v << '\n';
	//}


	//for (auto it = strings.begin(); it != strings.end(); it++)

	// Get the devices from the function
	//const auto& devices = getDevices();

	//// Displaying the devices in each category
	//for (const auto& category : devices) {
	//	std::cout << "Category: " << category.first << std::endl;
	//	for (const auto& device : category.second) {
	//		std::cout << " - " << device << std::endl;
	//	}
	//}


	/*for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << '\n';
	}

	std::cout << name << '\n'; */

//	DeviceManager manager;
//
//	// Creating some devices
//	Device* device1 = new Device("Printer");
//	Device* device2 = new Device("Scanner");
//	Device* device3 = new Device("Monitor");
//
//	// Adding devices to the manager under different categories
//	manager.addDevice("Output", device1);
//	manager.addDevice("Input", device2);
//	manager.addDevice("Output", device3);
//
//	// Accessing devices through getDevices()
//	const auto& devices = manager.getDevices();
//
//	// Displaying the devices in each category
//	for (const auto& category : devices) {
//		std::cout << "Category: " << category.first << std::endl;
//		for (const auto& device : category.second) {
//			std::cout << '\n' << "HOLYSHEESH " << category.first << '\n';
//			device->display();
//		}
//	}
//
//	// Clean up dynamically allocated memory
//	delete device1;
//	delete device2;
//	delete device3;
//}