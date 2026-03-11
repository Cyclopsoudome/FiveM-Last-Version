using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Newtonsoft.Json;

namespace HotelBookingSystem
{

    public class Room
    {
        public int RoomNumber { get; set; }
        public string Type { get; set; } = string.Empty; // Single, Double, Suite
        public decimal PricePerNight { get; set; }
        public bool IsAvailable { get; set; } = true;
    }

    public class Guest
    {
        public int Id { get; set; }
        public string Name { get; set; } = string.Empty;
        public string PassportNumber { get; set; } = string.Empty;
        public string ContactPhone { get; set; } = string.Empty;
    }

    public class Booking
    {
        public int BookingId { get; set; }
        public int GuestId { get; set; }
        public int RoomNumber { get; set; }
        public DateTime CheckInDate { get; set; }
        public DateTime CheckOutDate { get; set; }
        public int NumberOfGuests { get; set; }
        public decimal TotalCost => PricePerNight * NightsCount;
        public decimal PricePerNight { get; set; }
        public int NightsCount => (CheckOutDate - CheckInDate).Days;
    }

    
    public class HotelManager
    {
        private List<Room> _rooms = new();
        private List<Guest> _guests = new();
        private List<Booking> _bookings = new();
        private int _nextGuestId = 1;
        private int _nextBookingId = 1;
        private const string DataFile = "hotel_data.json";

        public HotelManager()
        {
            LoadData();
            
            if (_rooms.Count == 0)
            {
                _rooms.Add(new Room { RoomNumber = 101, Type = "Single", PricePerNight = 50 });
                _rooms.Add(new Room { RoomNumber = 102, Type = "Double", PricePerNight = 80 });
                _rooms.Add(new Room { RoomNumber = 201, Type = "Suite", PricePerNight = 150 });
            }
        }
